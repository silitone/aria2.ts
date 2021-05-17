
/* GIMP RGBA C-Source image dump (font.c) */
#include "font.h"

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[128 * 128 * 4 + 1];
} font = {
  128, 128, 4,
  "\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377"
  "\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\377\377"
  "\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377"
  "\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377"
  "\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\377\377\377\377"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377"
  "\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\377\377\377\377\377\377\377\377\0\0\0\0\377\377\377\377\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377\0\0\0\0\377\377\377\377\0\0\0\0"
  "\377\377\377\377\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\377\377\377\377"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"