#include <so/so_value_accesser.h>
#pragma force_active on

extern const float lbl_41_rodata_18;

extern "C" float fn_41_6A68(float* p, soModuleAccesser* acc) {
    float f = p[0];
    float v = soValueAccesser::getValueFloat(acc, 0x1100000C, 0);
    if (lbl_41_rodata_18 != p[1]) {
        f = f + p[1] * v;
    }
    return f;
}
