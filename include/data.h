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
 * Get archive block size.
 */
uint16_t ngxArcBlockSize(const NGXARC arc);

/**
 * Get archive block count.
 */
uint16_t ngxArcBlockCount(const NGXARC arc);

/**
 * Get bloc