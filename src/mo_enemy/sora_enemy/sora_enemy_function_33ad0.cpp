#include <so/so_value_accesser.h>

#pragma force_active on

extern "C" const float lbl_41_rodata_E28;

extern "C" int fn_41_33AD0(float* self, soModuleAccesser* acc) {
    int v = self[0];
    float f1 = soValueAccesser::getValueFloat(acc, 0x11000000, 0);
    if (lbl_41_rodata_E28 != self[1]) {
        v += self[1] * f1;
    }
    return v;
}
