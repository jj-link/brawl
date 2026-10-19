#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_41_rodata_E28;

extern "C" float fn_41_33B6C(float* self, soModuleAccesser* acc) {
    float f31 = self[0];
    float f1 = soValueAccesser::getValueFloat(acc, 0x11000000, 0);
    if (lbl_41_rodata_E28 != self[1]) {
        f31 = f31 + self[1] * f1;
    }
    return f31;
}
