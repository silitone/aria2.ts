#include <data.h>
#include <index.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

void* load(const char* fname, uint32_t* plen){
  FILE* 