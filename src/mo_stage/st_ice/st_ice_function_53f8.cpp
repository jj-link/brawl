#include <types.h>
#pragma force_active on

extern "C" const float lbl_62_rodata_80;

// The two float values are returned in the r3/r4 register pair as raw bits.
union StIcePair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_62_53F8() {
    StIcePair result;
    result.stick.x = lbl_62_rodata_80;
    result.stick.y = lbl_62_rodata_80;
    return result.packed;
}
