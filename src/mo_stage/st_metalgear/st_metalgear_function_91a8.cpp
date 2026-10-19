#include <types.h>
#pragma force_active on

extern "C" const float lbl_71_rodata_178;

// The two float halves are returned packed in the r3/r4 register pair.
union Pair71 {
    struct { float x, y; } f;
    struct { u32 a, b; } w;
    u64 packed;
};

extern "C" u64 fn_71_91A8(void) {
    Pair71 r;
    r.f.x = lbl_71_rodata_178;
    r.f.y = lbl_71_rodata_178;
    return r.packed;
}
