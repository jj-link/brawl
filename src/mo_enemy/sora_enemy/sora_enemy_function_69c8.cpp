#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_41_rodata_18;
}

#pragma push
#pragma relax_ieee on
#pragma fp_reassoc off
#pragma fp_contract off
#pragma peephole on

extern "C" int fn_41_69C8(const float* p, soModuleAccesser* acc) {
    int result = (int)p[0];
    float f2, f0;
    float f1 = soValueAccesser::getValueFloat(acc, 0x1100000C, 0);
    float zero = lbl_41_rodata_18;
    float f3 = p[1];

    if (zero != f3) {
        result += f3 * f1;
    }

    return result;
}

#pragma pop
