#include <types.h>
#pragma force_active on

extern "C" const float lbl_61_rodata_118;

union FloatPair {
    struct { float a, b; } f;
    struct { u32 hi, lo; } w;
    u64 packed;
};

extern "C" u64 fn_61_9A08(void) {
    FloatPair r;
    r.f.a = lbl_61_rodata_118;
    r.f.b = lbl_61_rodata_118;
    return r.packed;
}
