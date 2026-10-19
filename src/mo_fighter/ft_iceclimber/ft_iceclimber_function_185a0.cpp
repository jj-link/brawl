#include <types.h>
#pragma force_active on

extern "C" const float lbl_105_rodata_90;

// Two floats packed into the r3/r4 register pair as a 64-bit return value.
union IceClimberInputPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_105_185A0(void) {
    IceClimberInputPair result;
    result.stick.x = lbl_105_rodata_90;
    result.stick.y = lbl_105_rodata_90;
    return result.packed;
}
