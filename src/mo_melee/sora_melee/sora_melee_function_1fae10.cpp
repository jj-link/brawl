#pragma force_active on
#include <math.h>

struct Vec2f {
    float x, y;
};

extern "C" {
extern const float lbl_27_rodata_2CF0[];
extern float lbl_805A17F0;
extern float lbl_805A17F4;

void fn_27_1FAE10(Vec2f* v) {
    const float* c = lbl_27_rodata_2CF0;
    float limit;
    float scale;
    limit = c[8];
    scale = limit;
    scale = scale / lbl_805A17F0;
    v->x *= scale;
    v->y *= scale;

    if (v->x > limit) {
        v->x = limit;
    } else if (v->x < c[63]) {
        v->x = c[63];
    }

    if (v->y > c[8]) {
        v->y = c[8];
    } else if (v->y < c[63]) {
        v->y = c[63];
    }

    if ((float)__fabs(v->x) <= lbl_805A17F4) {
        v->x = c[0];
    }

    if ((float)__fabs(v->y) <= lbl_805A17F4) {
        v->y = c[0];
    }
}
}
