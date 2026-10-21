#include <types.h>
#pragma force_active on

extern "C" {
extern float lbl_805A34A8;
extern float lbl_805A34AC;

void fn_801BD33C(void* arg0, float farg0) {
    float var_f0;

    if (farg0 > lbl_805A34AC) {
        var_f0 = lbl_805A34AC;
    } else if (farg0 < lbl_805A34A8) {
        var_f0 = lbl_805A34A8;
    } else {
        var_f0 = farg0;
    }
    *(float*)((char*)arg0 + 0x8C) = var_f0;
}
}
