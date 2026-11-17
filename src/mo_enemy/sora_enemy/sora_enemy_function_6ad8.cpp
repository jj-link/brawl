#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" const float lbl_41_rodata_18;
extern "C" const float lbl_41_rodata_2C;
extern "C" float randf__Fv();

extern "C" float fn_41_6AD8(float* p, soModuleAccesser* acc) {
    float f31 = p[0];
    float f30 = p[2];
    float v = soValueAccesser::getValueFloat(acc, 0x1100000C, 0);
    if (lbl_41_rodata_18 != p[1]) {
        f31 = f31 + p[1] * v;
    }
    if (lbl_41_rodata_18 != p[3]) {
        f30 = f30 + p[3] * v;
    }
    if (f31 > f30) {
        f30 = f31;
    }
    if (f30 < f31) {
        return lbl_41_rodata_18;
    }
    return f30 == f31
        ? f30
        : f31 + (lbl_41_rodata_2C + (f30 - f31)) * randf__Fv();
}