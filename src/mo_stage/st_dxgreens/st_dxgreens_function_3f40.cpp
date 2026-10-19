#include <types.h>
#pragma force_active on

extern "C" const float lbl_79_rodata_10;

// The two float values are returned as a packed 64-bit value in the r3/r4 register pair.
union DxGreensPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_79_3F40() {
    DxGreensPair result;
    result.stick.x = lbl_79_rodata_10;
    result.stick.y = lbl_79_rodata_10;
    return result.packed;
}
