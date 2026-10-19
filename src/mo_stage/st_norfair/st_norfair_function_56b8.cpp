#include <types.h>
#pragma force_active on

extern "C" const float lbl_54_rodata_84;

// Two copies of the float constant are packed into one 8-byte return value (r3/r4).
union Pair {
    struct { float x, y; } f;
    struct { u32 a, b; } w;
    u64 packed;
};

extern "C" u64 fn_54_56B8(void) {
    Pair r;
    r.f.x = lbl_54_rodata_84;
    r.f.y = lbl_54_rodata_84;
    return r.packed;
}
