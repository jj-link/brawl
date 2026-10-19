#include <types.h>
#pragma force_active on

extern "C" const float lbl_49_rodata_58;

// The two float zeros are returned as a u64 in the r3/r4 register pair.
union KartInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_49_5CC4(void) {
    KartInputPair result;
    result.stick.x = lbl_49_rodata_58;
    result.stick.y = lbl_49_rodata_58;
    return result.packed;
}
