#include <types.h>
#pragma force_active on

extern "C" const float lbl_68_rodata_88;

// The two words are returned in the r3/r4 register pair.
union StPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_68_5AA4(void) {
    StPair result;
    result.stick.x = lbl_68_rodata_88;
    result.stick.y = lbl_68_rodata_88;
    return result.packed;
}
