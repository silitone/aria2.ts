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

 