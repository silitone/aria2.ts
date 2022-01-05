#include <data.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __DATA_DEBUG__
#define DLOG(fmt, ...) fprintf(stderr, fmt "\n",  ##__VA_ARGS__)
#else
#define DLOG(...)
#endif

struct ngx_archive_t {
  FILE* fl;
  uint16_t blkoff;
  uint16_t blksz;
  uint16_t blkcnt;
  int ronly;
};

struct ngx_ablock_t {
  uint16_t blkid;
  uint16_t blknxt;
  uint8_t* blkdata;
};

#define NGXMAGIC (0x5677ABCD)
#define NGXVERSION (0x1)
#define NGXBLKSIZE (512)

#pragma pack(push, 1)

struct ngx_block_t {
  uint16_t blknxt; /**< Next block */
  uint8_t blkdata[]; /**< Block data */
};

struct ngx_file_t {
  uint32_t magic; /**< archive file magic */
  uint32_t version; /**< archive version */
  uint32_t blkoff; /**< block offset from start */
  uint16_t blksz; /**< block size */
  uint16_t blkcnt; /**< total block count */
};

#pragma pack(pop)

/*
 * NGX resource archive structure.
 *
 * [0000-0015] ngx_file_t -- archive header information
 * [0016-????] ngx_block_t -- block headers
 *
 */

static FILE* ngxOpen(const char* filename, int readonly){
  if (readonly == 0){
    FILE* fl = fopen(filename, "r+");
    if (fl == 0){
      fl = fopen(filename, "w");
      if (fl == 0){ // Can't create new file
        return 0;
      }
      fclose(fl);
      fl = fopen(filename, "r+");
    }
    if (fl == 0){ // Still can't open file
      return 0;
    }
    return fl;
  }

  // readonly
  FILE* fl = fopen(filename, "r");
  if (fl == 0){
    return 0;
  }
  return fl;
}

static int ngxGetHeader(FILE* fl, struct ngx_file_t* pheader, int readonly){

  // Seek header
  if (fseek(fl, 0, SEEK_SET) != 0){
    return -1;
  }
  // Try to read header
  if (fread(pheader, sizeof(struct ngx_file_t), 1, fl) != 1 ){

    if (readonly != 0){
      return -1;
    }

    clearerr(fl);
    // If not present
    if (fseek(fl, 0, SEEK_SET) != 0){
      return -1;
    }

    // Generate new one
    pheader->magic = NGXMAGIC;
    pheader->version = NGXVERSION;
    pheader->blkoff = sizeof(struct ngx_file_t);
    pheader->blksz = NGXBLKSIZE;
    pheader->blkcnt = 0;

    // Update file
    if (fwrite(pheader, sizeof(struct ngx_file_t), 1, fl)  != 1){
      return -1;
    }

    fflush(fl);
  }
  return 0;
}

uint16_t ngxArcBlockSize(const NGXARC arc){
  if (arc != 0) {
    return arc->blksz;
  }
  return 0;
}

uint16_t ngxArcBlockCount(const NGXARC arc){
  if (arc != 0) {
    return arc->blkcnt;
  }
  return 0;
}

int ngxUpdateHeader(NGXARC arc, int readonly){
  if (readonly == 0){
    struct ngx_file_t fheader;
    fheader.magic = NGXMAGIC;
    fheader.version = NGXVERSION;
    fheader.blkoff = arc->blkoff;
    fheader.blksz = arc->blksz;
    fheader.blkcnt = arc->blkcnt;

    // Seek header
    if (fseek(arc->fl, 0, SEEK_SET) != 0){
      return -1;
    }

    // Update file
    if (fwrite(&fheader, sizeof(struct ngx_file_t), 1, arc->fl)  != 1){
      return -1;
    }

    fflush(arc->fl);
    return 0;
  }
  return -1;
}

#define MAX(A, B) ((A>B)?(A):(B))

NGXARC ngxArcInit(const char* filename, int readonly){
  NGXARC result = (NGXARC)malloc(sizeof(struct ngx_archive_t));
  FILE* fl = 0;
  struct ngx_file_t fheader;

  if (result == 0){
    return 0;
  }

  fl = ngxOpen(filename, readonly);
  if (fl == 0){ // Can't open file
    goto FREE_RESULT;
  }

  if (ngxGetHeader(fl, &fheader, readonly) != 0){
    goto FREE_RESULT;
  }

  if (fheader.magic != NGXMAGIC){
    goto FREE_RESULT;
  }

  if (fheader.version != NGXVERSION){
    goto FREE_RESULT;
  }

  if (fheader.blksz != NGXBLKSIZE ) {
    goto FREE_RESULT;
  }

  result->fl = fl;
  result->blkoff = fheader.blkoff;
  result->blksz = fheader.blksz;
  result->blkcnt = fheader.blkcnt;
  result->ronly = readonly;
  return result;

FREE_RESULT:
  free(result);
  if (fl != 0){
    fclose(fl);
  }
  return 0;
}

void ngxArcCleanup(NGXARC* oarc){
  if ((oarc != 0)&&(*oarc != 0)){
    fclose((*oarc)->fl);
    free(*oarc);
    *oarc = 0;
  }
}

int ngxGetBlock(NGXARC arc, uint16_t blkid, NGXBLK blk, int readonly){
  int offset = arc->blkoff + arc->blksz*blkid;
  struct ngx_block_t* fblk = 0;

  fblk = (struct ngx_block_t*) malloc(arc->blksz);
  if (fblk == 0){
    return -1;
  }

  // Seek block
  if (fseek(arc->fl, offset, SEEK_SET) != 0){
    free(fblk);
    return -1;
  }

  // Try to read block
  if (fread(fblk, arc->blksz, 1, arc->fl) != 1 ){
    if (readonly != 0){
      free(fblk);
      return -1;
    }

    clearerr(arc->fl);

    // If not present
    if (fseek(arc->fl, offset, SEEK_SET) != 0){
      free(fblk);
      return -1;
    }

    // Generate new one
    fblk->blknxt = 0xFFFF;
    memset(fblk->blkdata, 0, arc->blksz - sizeof(struct ngx_block_t));

    // Update file
    if (fwrite(fblk, arc->blksz, 1, arc->fl)  != 1){
      free(fblk);
      ret