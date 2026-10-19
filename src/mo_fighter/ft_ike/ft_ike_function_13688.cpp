#include <types.h>
#pragma force_active on

extern "C" const float lbl_119_rodata_9C;

// The two float values are returned packed in the r3/r4 register pair.
union IkeInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_119_13688(void) {
    IkeInputPair result;
    result.stick.x = lbl_119_rodata_9C;
    result.stick.y = lbl_119_rodata_9C;
    return result.packed;
}
