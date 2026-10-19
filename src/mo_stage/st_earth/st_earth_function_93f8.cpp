#include <types.h>
#pragma force_active on

extern "C" const float lbl_66_rodata_178;

// The two float results are returned as raw 32-bit words in the r3/r4 pair.
union FloatPairBits {
    struct { float x, y; } f;
    struct { u32 first, second; } w;
    u64 packed;
};

extern "C" u64 fn_66_93F8() {
    FloatPairBits r;
    r.f.x = lbl_66_rodata_178;
    r.f.y = lbl_66_rodata_178;
    return r.packed;
}
