#include <math.h>

#pragma force_active on

extern float lbl_41_rodata_C90;

extern "C" float fn_41_1B044(float p1, float p2, float p3, float p4) {
    const float* t = &lbl_41_rodata_C90;

    if (t[4] == p1) {
        p1 = p3;
    } else if (t[5] == p1) {
        double d = fabs((double)p3);
        p1 = (float)d;
    } else if (t[6] == p1) {
        double d = fabs((double)p3);
        p1 = -(float)d;
    }

    if (t[7] == p1) {
        return p1;
    }
    if (t[2] == p1) {
        return p1;
    }
    if (t[3] == p2) {
        return p1;
    }
    return p1 + p2 * p4;
}
