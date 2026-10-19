#include <types.h>
#pragma force_active on

extern "C" const float lbl_109_rodata_48;

// The two 32-bit words of the float constant are returned in the r3/r4 register pair.
union GanonFloatPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_109_11A28() {
    GanonFloatPair result;
    result.stick.x = lbl_109_rodata_48;
    result.stick.y = lbl_109_rodata_48;
    return result.packed;
}
