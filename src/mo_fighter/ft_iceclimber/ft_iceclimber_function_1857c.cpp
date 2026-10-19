#include <types.h>
#pragma force_active on

extern "C" const float lbl_105_rodata_90;

// Two floats are stored to the stack and reloaded as a 64-bit r3/r4 pair.
union FloatPairBits {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_105_1857C(void) {
    FloatPairBits result;
    result.stick.x = lbl_105_rodata_90;
    result.stick.y = lbl_105_rodata_90;
    return result.packed;
}
