#include <types.h>
#pragma force_active on

extern "C" const float lbl_121_rodata_80;

// The two float halves are returned in the r3/r4 register pair as a 64-bit value.
union ToonLinkInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_121_14890(void) {
    ToonLinkInputPair result;
    result.stick.x = lbl_121_rodata_80;
    result.stick.y = lbl_121_rodata_80;
    return result.packed;
}
