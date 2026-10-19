#include <types.h>
#pragma force_active on

extern "C" const float lbl_74_rodata_D0;

// The two floats are returned packed in the r3/r4 register pair.
union PlanktonPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_74_5B90(void) {
    PlanktonPair result;
    result.stick.x = lbl_74_rodata_D0;
    result.stick.y = lbl_74_rodata_D0;
    return result.packed;
}
