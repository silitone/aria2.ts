
#include <device.h>
#include <model.h>
#include <stdio.h>
#include <stdlib.h>
#include <data.h>

NGXMODEL mdl = 0;

double angle = 0.0;
void Render(double dt, void* ptr) {
  ngxLookAt(10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  ngxRotate(angle, 0.0f, 1.0f, 0.0f);
  ngxModelDraw(mdl);
}

int prs = 0;
void Keys(int key, void* ptr) {
  NGXDEVICE dev = (NGXDEVICE) ptr;