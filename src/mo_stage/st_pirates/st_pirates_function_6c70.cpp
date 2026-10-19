#include <types.h>
#pragma force_active on

extern "C" const float lbl_52_rodata_E8;

// The two float values are returned in the r3/r4 register pair.
union PairInput {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_52_6C70() {
    PairInput result;
    result.stick.x = lbl_52_rodata_E8;
    result.stick.y = lbl_52_rodata_E8;
    return result.packed;
}
