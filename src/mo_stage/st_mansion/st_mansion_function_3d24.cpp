#include <types.h>
#pragma force_active on

extern "C" const float lbl_47_rodata_48;

// The two float bit patterns are returned in the r3/r4 register pair.
union St33Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_47_3D24() {
    St33Pair result;
    result.stick.x = lbl_47_rodata_48;
    result.stick.y = lbl_47_rodata_48;
    return result.packed;
}
