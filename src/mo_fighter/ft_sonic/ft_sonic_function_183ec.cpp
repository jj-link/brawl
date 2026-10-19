#include <math.h>
#pragma force_active on

extern const float lbl_123_rodata_A0;

extern "C" {
int fn_123_183EC(float x)
{
    int r = 0;
    double d = fabs((double)x);
    float f = (float)d;
    if (f < lbl_123_rodata_A0) {
        r = 1;
    }
    return r;
}
}
