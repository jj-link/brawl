#include <types.h>
#pragma force_active on

extern "C" const float lbl_122_rodata_A0;

// The two float values are returned as raw words in the r3/r4 register pair.
union SnakePair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_122_18FC0() {
    SnakePair result;
    result.stick.x = lbl_122_rodata_A0;
    result.stick.y = lbl_122_rodata_A0;
    return result.packed;
}
