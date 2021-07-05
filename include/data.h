/**
 * @file data.h
 * @author timur
 *
 * Resources archive implementation.
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#ifndef __DATA_HEADER__
#define __DATA_HEADER__

typedef struct ngx_ablock_t* NGXBLK;

typedef struct ngx_archive_t* NGXARC;

/**
 * Create new archive.
 */
NGXARC ngxArcInit(const char* filename, int readonly);

/**
 * Cleanup archive.
 */
void ngxArcCleanup(NGXARC* oarc);

/**
 * G