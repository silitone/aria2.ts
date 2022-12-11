
#include <data.h>
#include <index.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>


#define EXPECT(cond)\
  if (!(cond)){\
    fprintf(stderr, "Error: %s at %s:%d\n", #cond, __FILE__, __LINE__);\
    exit(-1);\
  } else {\
    fprintf(stderr, "EXPECTED: %s at %s:%d\n", #cond, __FILE__, __LINE__);\
  }

void test000(){
  NGXINDEX index = ngxIndexInit();
  EXPECT(index != 0);

  EXPECT(ngxIndexSize(0) == 0);
  EXPECT(ngxIndexCap(0) == 0);

  EXPECT(ngxIndexSize(index) == 0);
  EXPECT(ngxIndexCap(index) == 33);