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
  