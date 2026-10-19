#include <types.h>
#pragma force_active on

extern "C" const float lbl_49_rodata_58;

// The eight-byte value is returned in the r3/r4 register pair.
union KartPairBits {
    struct { float x, y; } floats;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_49_5CE8() {
    KartPairBits result;
    result.floats.x = lbl_49_rodata_58;
    result.floats.y = lbl_49_rodata_58;
    return result.packed;
}
