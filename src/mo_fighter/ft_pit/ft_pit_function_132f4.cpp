#include <math.h>
#pragma force_active on

extern const float lbl_112_rodata_9C;

extern "C" int fn_112_132F4(double x)
{
    int ret = 0;
    double d = fabs(x);
    float ax = (float)d;
    if (ax < lbl_112_rodata_9C) {
        ret = 1;
    }
    return ret;
}
