#include <types.h>
#pragma force_active on

extern "C" const float lbl_76_rodata_4C;

// The two float values are returned as the r3/r4 pair of integer words.
union StPairWords {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_76_2FDC(void*) {
    StPairWords result;
    result.stick.x = lbl_76_rodata_4C;
    result.stick.y = lbl_76_rodata_4C;
    return result.packed;
}
