#include <types.h>
#pragma force_active on

extern "C" const float lbl_96_rodata_530;

union KirbyFloatPair {
    float f[2];
    u64 packed;
};

extern "C" u64 fn_96_23DF8(void) {
    KirbyFloatPair result;
    result.f[0] = lbl_96_rodata_530;
    result.f[1] = lbl_96_rodata_530;
    return result.packed;
}
