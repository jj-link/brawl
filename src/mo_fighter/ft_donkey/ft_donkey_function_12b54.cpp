#include <types.h>
#pragma force_active on

extern "C" const float lbl_92_rodata_B0;

// Two float copies of the same constant, returned packed in the r3/r4 pair.
union DonkeyInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_92_12B54(void) {
    DonkeyInputPair result;
    result.stick.x = lbl_92_rodata_B0;
    result.stick.y = lbl_92_rodata_B0;
    return result.packed;
}
