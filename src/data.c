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
  uint8_t* blk