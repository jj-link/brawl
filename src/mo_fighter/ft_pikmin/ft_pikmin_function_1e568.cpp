#include <math.h>
#pragma force_active on

extern const float lbl_113_rodata_A0;

extern "C" int fn_113_1E568(double x)
{
    int r = 0;
    double t = fabs(x);
    float ax = (float)t;
    if (ax < lbl_113_rodata_A0) {
        r = 1;
    }
    return r;
}
