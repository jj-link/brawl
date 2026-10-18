#include <math.h>
#pragma force_active on

float rsqrtf(float);

extern float lbl_41_rodata_CB4;
extern float lbl_41_rodata_C9C;

extern "C" float fn_41_1D178(float* v) {
    float s = v[2] * v[2] + (v[0] * v[0] + v[1] * v[1]);
    double d = fabs((double)s);
    float a = (float)d;
    if (a <= lbl_41_rodata_CB4) {
        return lbl_41_rodata_C9C;
    }
    return s * rsqrtf(s);
}
