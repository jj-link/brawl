#include <types.h>
#pragma force_active on

extern "C" const float lbl_123_rodata_70;

// The two float words are returned in the r3/r4 register pair.
union SonicInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_123_14170(void) {
    SonicInputPair result;
    result.stick.x = lbl_123_rodata_70;
    result.stick.y = lbl_123_rodata_70;
    return result.packed;
}
