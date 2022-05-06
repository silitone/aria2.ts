#include <device.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>


#define NGXLOGFNAME ("ngx.log")

enum ngx_state_t {
    NGX_INIT = 0,
    NGX_LOOP = 1,
    NGX_CLOS = 2
};

struct ngx_xdata_t {
    Display* dpy;
    Window win;
    GLXContext glc;
    Atom WM_DELETE_WINDOW;
};

struct ngx_device_t {
    struct ngx_xdata_t dsp;
    uint64_t counter;
    int state;
    struct timespec start;
    NGXDRAWFUNC drawfunc;
    NGXKEYFUNC keyfunc;
    NGXLOADRESOURCEFUNC loadfunc;
    void* ptr;
    uint8_t keys[USHRT_MAX];
    int persp;
    int width;
    int height;
};

static void ngxDefaultKey(int key, void* ptr) {
    ;
}

static void ngxDefaultLoad(int load, void* ptr) {
    ;
}

static double angle = 0.0;

static void ngxDefaultDraw(double dt, void* ptr) {
    angle += dt * 10.0;

    gluLookAt(10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f); // Красный
    glVertex3f(0.0f, 1.0f, 0.0f); // Верх треугольника (Передняя)
    glColor3f(0.0f, 1.0f, 0.0f); // Зеленный
    glVertex3f(-1.0f, -1.0f, 1.0f); // Левая точка
    glColor3f(0.0f, 0.0f, 1.0f); // Синий
    glVertex3f(1.0f, -1.0f, 1.0f); // Правая точка

    glColor3f(1.0f, 0.0f, 0.0f); // Красная
    glVertex3f(0.0f, 1.0f, 0.0f); // Верх треугольника (Правая)
    glColor3f(0.0f, 0.0f, 1.0f); // Синия
    glVertex3f(1.0f, -1.0f, 1.0f); // Лево треугольника (Правая)
    glColor3f(0.0f, 1.0f, 0.0f); // Зеленная
    glVerte