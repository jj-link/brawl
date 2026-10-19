#include <types.h>
#pragma force_active on

extern "C" const float lbl_74_rodata_D0;

// The two float values are returned in the r3/r4 register pair.
union StPlanktonInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_74_5B6C() {
    StPlanktonInputPair result;
    result.stick.x = lbl_74_rodata_D0;
    result.stick.y = lbl_74_rodata_D0;
    return result.packed;
}
