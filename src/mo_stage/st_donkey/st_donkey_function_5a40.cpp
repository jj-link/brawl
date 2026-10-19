#include <types.h>
#pragma force_active on

extern "C" const float lbl_50_rodata_A0;

// The two words are returned in the r3/r4 register pair.
union DonkeyFloatPair {
    struct { float x, y; } floats;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_50_5A40() {
    DonkeyFloatPair result;
    result.floats.x = lbl_50_rodata_A0;
    result.floats.y = lbl_50_rodata_A0;
    return result.packed;
}
