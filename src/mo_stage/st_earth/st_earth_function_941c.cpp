#include <types.h>
#pragma force_active on

extern "C" const float lbl_66_rodata_178;

union FloatPair {
    struct { float x, y; } f;
    struct { u32 first, second; } w;
    u64 packed;
};

extern "C" u64 fn_66_941C(void) {
    FloatPair result;
    result.f.x = lbl_66_rodata_178;
    result.f.y = lbl_66_rodata_178;
    return result.packed;
}
