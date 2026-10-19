#include <types.h>
#pragma force_active on

extern "C" const float lbl_113_rodata_64;

union PikminFloatPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_113_1C0D8(void) {
    PikminFloatPair result;
    result.stick.x = lbl_113_rodata_64;
    result.stick.y = lbl_113_rodata_64;
    return result.packed;
}
