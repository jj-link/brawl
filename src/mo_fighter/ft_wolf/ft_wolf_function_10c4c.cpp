#include <types.h>
#pragma force_active on

extern "C" const float lbl_125_rodata_1C;

// The two float values are returned packed in the r3/r4 register pair.
union WolfInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_125_10C4C(void) {
    WolfInputPair result;
    result.stick.x = lbl_125_rodata_1C;
    result.stick.y = lbl_125_rodata_1C;
    return result.packed;
}
