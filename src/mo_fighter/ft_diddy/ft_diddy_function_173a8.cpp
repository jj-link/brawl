#include <types.h>
#pragma force_active on

extern "C" const float lbl_115_rodata_F8;

union DiddyPair {
    struct { float a, b; } f;
    struct { u32 first, second; } w;
    u64 packed;
};

extern "C" u64 fn_115_173A8(void) {
    DiddyPair r;
    r.f.a = lbl_115_rodata_F8;
    r.f.b = lbl_115_rodata_F8;
    return r.packed;
}
