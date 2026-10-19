#include <types.h>
#pragma force_active on

extern "C" const float lbl_102_rodata_80;

union KoopaInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_102_1BFF4(void) {
    KoopaInputPair result;
    result.stick.x = lbl_102_rodata_80;
    result.stick.y = lbl_102_rodata_80;
    return result.packed;
}
