#include <types.h>
#pragma force_active on

extern "C" const float lbl_122_rodata_A0;

// The two-float value is returned in the r3/r4 register pair.
union SnakeInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_122_18F9C(void*) {
    SnakeInputPair result;
    result.stick.x = lbl_122_rodata_A0;
    result.stick.y = lbl_122_rodata_A0;
    return result.packed;
}
