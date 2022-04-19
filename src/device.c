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

struct ngx_devi