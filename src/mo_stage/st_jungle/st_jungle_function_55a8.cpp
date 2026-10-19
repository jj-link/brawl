#include <types.h>
#pragma force_active on

extern "C" const float lbl_51_rodata_8C;

// The eight-byte value is returned in the r3/r4 register pair.
union StJungleInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_51_55A8(void) {
    StJungleInputPair result;
    result.stick.x = lbl_51_rodata_8C;
    result.stick.y = lbl_51_rodata_8C;
    return result.packed;
}
