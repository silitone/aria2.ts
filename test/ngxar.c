#include <data.h>
#include <index.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

void* load(const char* fname, uint32_t* plen){
  FILE* input = fopen(fname, "r");
  int32_t len = 0;
  void* result = 0;

  if (input == 0){
    return 0;
  }

  if (fseek(input, 0, SEEK_END) != 0) {
    fclose(input);
    return 0;
  }

  len = ftell(input);

  if (len < 0){
    fclose(input);
    return 0;
  }

  result = malloc(len);
  if (result == 0){
    fclose(input);
    return 0;
  }

  if (fseek(input, 0, SEEK_SET) != 0) {
    fclose(input);
    free(result);
    return 0;
  }

  if (fread(result, 1,