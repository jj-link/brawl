#include <types.h>
#pragma force_active on

extern "C" const float lbl_93_rodata_80;

// The two float values are returned in the r3/r4 register pair.
union FloatPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_93_14844() {
    FloatPair result;
    result.stick.x = lbl_93_rodata_80;
    result.stick.y = lbl_93_rodata_80;
    return result.packed;
}
