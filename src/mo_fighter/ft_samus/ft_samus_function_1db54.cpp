#include <types.h>
#pragma force_active on

extern "C" const float lbl_94_rodata_90;

// The two float values are returned in the r3/r4 register pair as a packed 64-bit value.
union Samus94Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_94_1DB54(void) {
    Samus94Pair result;
    result.stick.x = lbl_94_rodata_90;
    result.stick.y = lbl_94_rodata_90;
    return result.packed;
}
