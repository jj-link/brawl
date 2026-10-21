#pragma force_active on
#include <math.h>

extern "C" void fn_80294D68(float* dst, const float* src) {
    float a = fabs(src[0]);
    float b = src[1];
    float c = src[2];
    b = fabs(b);
    c = fabs(c);
    float d = fabs(src[3]);
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
}
