
#include <device.h>
#include <model.h>
#include <stdio.h>
#include <stdlib.h>
#include <data.h>
#include <string.h>

#include "cell.h"
#include "font.h"
#include "junks.h"

NGXDEVICE dev = 0;

typedef struct object_t {
    float x;
    float y;
    int f;
    float timeout;
} object_t;

object_t player;

ngx_sprite_t spr;
ngx_sprite_t fontSpr;

unsigned int grass = 0;
unsigned int ptex = 0;
unsigned int font = 0;

const char* text = "FLX v.0.0.1 by masscry";

void Render(double dt, void* ptr) {