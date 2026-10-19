#include <types.h>
#pragma force_active on

extern "C" const float lbl_96_rodata_530;

// The two float results are returned in the r3/r4 register pair.
union KirbyFloatPair {
    struct { float x, y; } pair;
    u64 packed;
};

extern "C" u64 fn_96_23DD4(void) {
    KirbyFloatPair result;
    result.pair.x = lbl_96_rodata_530;
    result.pair.y = lbl_96_rodata_530;
    return result.packed;
}
