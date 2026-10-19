#include <types.h>
#pragma force_active on

extern "C" const float lbl_125_rodata_1C;

// Two floats packed into the r3/r4 register pair.
union WolfFloatPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_125_10C70(void) {
    WolfFloatPair result;
    result.stick.x = lbl_125_rodata_1C;
    result.stick.y = lbl_125_rodata_1C;
    return result.packed;
}
