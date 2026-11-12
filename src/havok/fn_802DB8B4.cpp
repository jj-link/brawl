#include <types.h>
#pragma force_active on

extern "C" void fn_802DB8B4(float* a, const float* b, float** c, float* d) {
    const float s = b[1];
    const float s2 = b[2];
    float* const p = *c;
    d[1] = a[2] * s;
    d[2] = a[3] * s;
    d[3] = a[1];
    d[4] = a[4];
    d[5] = a[5];
    d[0] = 1.0f;
    p[7] = a[0] * s2;
    *c = p + 8;
}