#include <conftree.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct config_pair_t config_pair_t;

typedef struct conf_number_t {
  int type;
  double val;
} conf_number_t;

typedef struct conf_string_t {
  int type;
  char* val;
} conf_string_t;

typedef struct conf_block_t {
  int type;
  config_pair_t* val;
} conf_block_t;

typedef union config_value_t {
  int type;
  conf_number_t num;
  conf