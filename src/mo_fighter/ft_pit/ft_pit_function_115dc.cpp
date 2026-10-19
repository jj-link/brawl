#include <types.h>
#pragma force_active on

extern "C" const float lbl_112_rodata_3C;

union PitInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_112_115DC(void) {
    PitInputPair result;
    result.stick.x = lbl_112_rodata_3C;
    result.stick.y = lbl_112_rodata_3C;
    return result.packed;
}
