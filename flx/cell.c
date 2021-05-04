#include "cell.h"

static const struct {
  uint32_t width;
  uint32_t height;
  uint32_t bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */
  uint8_t pixel_data[8 * 8 * 4 + 1];
} flCellPattern = {
  8, 8, 4,
  "\0|\0\377\0|\0\377\0|\0\377\0\242\0\377\0|\0\377\0|\0\377\0\242\0\377\0|"
  "\0\377\0\242\0\377\0|\0\377\0|\0