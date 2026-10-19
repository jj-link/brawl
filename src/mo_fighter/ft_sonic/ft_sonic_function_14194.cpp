#include <types.h>
#pragma force_active on

extern "C" const float lbl_123_rodata_70;

union FloatPair {
    float f[2];
    u64 packed;
};

extern "C" u64 fn_123_14194(void) {
    FloatPair result;
    result.f[0] = lbl_123_rodata_70;
    result.f[1] = lbl_123_rodata_70;
    return result.packed;
}
