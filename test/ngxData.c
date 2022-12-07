
#include <data.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define EXPECT(cond)\
  if (!(cond)){\
    fprintf(stderr, "Error: %s at %s:%d\n", #cond, __FILE__, __LINE__);\
    exit(-1);\
  }

void test000(const char* fname){
  NGXARC arc = 0;
  NGXBLK block = 0;
  NGXBLK nblk = 0;

  arc = ngxArcInit(fname, 0);

  EXPECT(arc != 0);

  EXPECT(ngxArcBlock(arc, 0xFFFF) == 0); // Invalid block id

  block = ngxArcBlock(arc, 0);