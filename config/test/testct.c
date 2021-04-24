#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <conftree.h>

#define EXPECT(cond) \
  if (!(cond)){\
    fprintf(stderr, "ERROR: %s at %s:%d\n", #cond