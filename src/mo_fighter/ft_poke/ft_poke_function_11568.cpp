#include <types.h>
#pragma force_active on

extern "C" const float lbl_116_rodata_18;

union FloatPair {
    float f[2];
    u64 packed;
};

extern "C" u64 fn_116_11568(void) {
    FloatPair result;
    result.f[0] = lbl_116_rodata_18;
    result.f[1] = lbl_116_rodata_18;
    return result.packed;
}
