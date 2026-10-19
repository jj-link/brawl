#include <types.h>
#pragma force_active on

extern "C" const float lbl_71_rodata_178;

// The two float halves are returned as a packed 64-bit value in the r3/r4 pair.
union MetalgearPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_71_9184(void) {
    MetalgearPair result;
    result.stick.x = lbl_71_rodata_178;
    result.stick.y = lbl_71_rodata_178;
    return result.packed;
}
