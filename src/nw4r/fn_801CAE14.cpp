#include <types.h>
#pragma force_active on

extern "C" {
extern float lbl_805A3630;
extern float lbl_805A3634;

void fn_801CAE14(void* arg0, float farg0) {
    float var_f0;

    if (farg0 > lbl_805A3630) {
        var_f0 = lbl_805A3630;
    } else if (farg0 < lbl_805A3634) {
        var_f0 = lbl_805A3634;
    } else {
        var_f0 = farg0;
    }
    *(float*)((char*)arg0 + 0x28) = var_f0;
}
}
