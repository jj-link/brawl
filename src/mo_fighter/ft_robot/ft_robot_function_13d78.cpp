#include <types.h>
#pragma force_active on

extern "C" const float lbl_120_rodata_80;

// The two float halves are returned packed in the r3/r4 register pair.
union Fn13D78Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_120_13D78(void) {
    Fn13D78Pair result;
    result.stick.x = lbl_120_rodata_80;
    result.stick.y = lbl_120_rodata_80;
    return result.packed;
}
