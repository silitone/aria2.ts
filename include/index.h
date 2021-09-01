#include <stdint.h>
#include <stddef.h>
#include <data.h>

#ifndef __INDEX_HEADER__
#define __INDEX_HEADER__

typedef struct ngx_index_t* NGXINDEX;

typedef struct ngx_entry_t* NGXENTRY;

NGXINDEX ngxIndexInit();

void ngxIndexCleanup(NGXINDEX* pindex);

NGXENTRY ngxIndexInse