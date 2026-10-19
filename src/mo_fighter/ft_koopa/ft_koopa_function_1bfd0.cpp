#include <types.h>
#pragma force_active on

extern "C" const float lbl_102_rodata_80;

union FloatPairBits {
    float f[2];
    u64 packed;
};

extern "C" u64 fn_102_1BFD0(void) {
    FloatPairBits result;
    result.f[0] = lbl_102_rodata_80;
    result.f[1] = lbl_102_rodata_80;
    return result.packed;
}
