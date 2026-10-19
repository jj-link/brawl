#include <types.h>
#pragma force_active on

extern "C" const float lbl_115_rodata_F8;

// Returns a pair of floats packed into the r3/r4 register pair.
union FloatPair {
    float f[2];
    u64 packed;
};

extern "C" u64 fn_115_17384() {
    FloatPair result;
    result.f[0] = lbl_115_rodata_F8;
    result.f[1] = lbl_115_rodata_F8;
    return result.packed;
}
