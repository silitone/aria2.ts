
#include <device.h>
#include <model.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glu.h>

#pragma pack(push, 1)

struct ngx_vertex_t {
    float v[3];
    float t[2];
    float n[3];
};

struct ngx_model_t {
    uint16_t id;
    uint16_t vcnt;
    struct ngx_vertex_t vdt[];
};

#pragma pack(pop)

void ngxModelDraw(const NGXMODEL mdl) {
    if (mdl == 0) {
        return;
    }

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < mdl->vcnt; ++i) {
        glColor3f(fabsf(mdl->vdt[i].n[0]), fabsf(mdl->vdt[i].n[1]), fabsf(mdl->vdt[i].n[2]));
        //    glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3fv(mdl->vdt[i].v);
    }
    glEnd();
}

void ngxQuad(float x, float y, float w, float h) {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + w, y, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + w, y + h, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + w, y + h, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + h, 0.0f);
