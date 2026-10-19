#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_122_rodata_114;

int fn_122_201C8(double x)
{
    int r = 0;
    double d = fabs(x);
    float a = (float)d;
    if (a < lbl_122_rodata_114) {
        r = 1;
    }
    return r;
}
}
