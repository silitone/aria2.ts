#include <data.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]){

  if (argc != 2){
    fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
    return -1;
  }

  NGXARC arc = ngxArcInit(argv[1], 1);
  if (arc == 0){
    fprintf(stderr, "Can't open %s\