#include <types.h>
#pragma force_active on

extern "C" const float lbl_54_rodata_84;

// The two float values are returned packed in the r3/r4 register pair.
union NorfairPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_54_5694(void) {
    NorfairPair result;
    result.stick.x = lbl_54_rodata_84;
    result.stick.y = lbl_54_rodata_84;
    return result.packed;
}
