#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_96_rodata_570;
extern const float lbl_96_rodata_578;
float rsqrtf__Ff(float);

struct Vec2 {
    float x;
    float y;
};

float fn_96_28A30(Vec2* v) {
    float sum = v->x * v->x + v->y * v->y;
    double d = fabs((double)sum);
    float mag = (float)d;
    if (mag <= lbl_96_rodata_578) {
        return lbl_96_rodata_570;
    }
    return sum * rsqrtf__Ff(sum);
}
}
