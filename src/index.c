
#include <index.h>

#include <stdlib.h>
#include <string.h>

uint32_t sdbm(const void* data, size_t datalen, uint32_t init) {
  uint8_t* cursor = (uint8_t*)data;
  uint32_t result = init;
  int c;

  while (datalen--> 0){
    c = *cursor++;
    result = c + (result << 6) + (result << 16) - result;
  }
  return result;
}

#define NGXINITENTRY (33)
#define NGXINITAPPND (NGXINITENTRY + 1)
#define NGXINITSTLEN (13)

#pragma pack(push, 1)

struct ngx_entry_t {
  uint16_t value; // 2
  char key[NGXINITSTLEN]; // 13
};

struct ngx_findex_t {
  uint16_t size; // 2
  uint16_t cap; // 2
  char reserved[NGXINITSTLEN - 2]; // 11
  struct ngx_entry_t entries[];
};

#pragma pack(pop)

struct ngx_index_t {
  uint16_t size;
  uint16_t cap;
  NGXENTRY entries;
};

NGXINDEX ngxIndexInit(){
  NGXINDEX index = malloc(sizeof(struct ngx_index_t));
  if (index == 0){