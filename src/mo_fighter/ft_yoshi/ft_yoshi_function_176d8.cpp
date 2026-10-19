#include <types.h>
#pragma force_active on

extern "C" const float lbl_95_rodata_130;

union FloatPairBits {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_95_176D8(void) {
    FloatPairBits result;
    result.stick.x = lbl_95_rodata_130;
    result.stick.y = lbl_95_rodata_130;
    return result.packed;
}
