#include <types.h>
#pragma force_active on

extern "C" const float lbl_62_rodata_80;

// The eight-byte result is returned in the r3/r4 register pair.
union StIcePair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_62_53D4(void) {
    StIcePair result;
    result.stick.x = lbl_62_rodata_80;
    result.stick.y = lbl_62_rodata_80;
    return result.packed;
}
