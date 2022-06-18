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
    glVertex3f(1.0f, -1.0f, -1.0f); // Право треугольника (Правая)

    glColor3f(1.0f, 0.0f, 0.0f); // Красный
    glVertex3f(0.0f, 1.0f, 0.0f); // Низ треугольника (Сзади)
    glColor3f(0.0f, 1.0f, 0.0f); // Зеленный
    glVertex3f(1.0f, -1.0f, -1.0f); // Лево треугольника (Сзади)
    glColor3f(0.0f, 0.0f, 1.0f); // Синий
    glVertex3f(-1.0f, -1.0f, -1.0f); // Право треугольника (Сзади)

    glColor3f(1.0f, 0.0f, 0.0f); // Красный
    glVertex3f(0.0f, 1.0f, 0.0f); // Верх треугольника (Лево)
    glColor3f(0.0f, 0.0f, 1.0f); // Синий
    glVertex3f(-1.0f, -1.0f, -1.0f); // Лево треугольника (Лево)
    glColor3f(0.0f, 1.0f, 0.0f); // Зеленный
    glVertex3f(-1.0f, -1.0f, 1.0f); // Право треугольника (Лево)

    glEnd();
}

NGXDEVICE ngxInit() {
    NGXDEVICE dev = 0;
    time_t now = 0;
    struct tm nowtm;
    char buffer[256];
    FILE* log = 0;

    log = fopen(NGXLOGFNAME, "w");
    if (log == 0) {
        fprintf(stderr, "Failed to open log file %s\n", NGXLOGFNAME);
        return 0;
    }

    now = time(0);
    localtime_r(&now, &nowtm);
    strftime(buffer, 256, "%d %b %Y %H:%M:%S", &nowtm);

    fprintf(log, "=== NGX ===\n");
    fprintf(log, "Current time: %s\n", buffer);

    dev = malloc(sizeof (struct ngx_device_t));
    if (dev == 0) {
        fprintf(log, "Failed to allocate memory for device\n");
        fclose(log);
        return 0;
    }

    memset(&(dev->dsp), 0, sizeof (struct ngx_xdata_t));
    dev->counter = 0;
    dev->state = NGX_INIT;
    clock_gettime(CLOCK_MONOTONIC, &dev->start);
    dev->drawfunc = ngxDefaultDraw;
    dev->keyfunc = ngxDefaultKey;
    dev->loadfunc = ngxDefaultLoad;
    memset(dev->keys, 0, USHRT_MAX);
    dev->persp = 0;
    dev->width = 800;
    dev->height = 600;
    fclose(log);
    return dev;
}

double ngxNow(const NGXDEVICE dev) {
    struct timespec ts;
    struct timespec start;

    if (dev == 0) {
        return -1.0;
    }
    start = dev->start;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    if (start.tv_nsec < ts.tv_nsec) {
        return (ts.tv_sec - start.tv_sec) + (ts.tv_nsec - start.tv_nsec)*1.0e-9;
    }
    return (ts.tv_sec - start.tv_sec - 1) + (ts.tv_nsec - start.tv_nsec + 1e9)*1.0e-9;
}

int ngxLog(const NGXDEVICE dev, const char* format, ...) {
    F