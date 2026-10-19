#include <types.h>
#pragma force_active on

extern "C" const float lbl_92_rodata_B0;

// The two float values are returned as raw bits in the r3/r4 register pair.
union DonkeyFloatPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_92_12B30(void) {
    DonkeyFloatPair result;
    result.stick.x = lbl_92_rodata_B0;
    result.stick.y = lbl_92_rodata_B0;
    return result.packed;
}
