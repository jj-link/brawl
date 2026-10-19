#include <types.h>
#pragma force_active on

extern "C" const float lbl_78_rodata_A8;

// The two float values are returned in the r3/r4 register pair.
union Fn78Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_78_4A44() {
    Fn78Pair result;
    result.stick.x = lbl_78_rodata_A8;
    result.stick.y = lbl_78_rodata_A8;
    return result.packed;
}
