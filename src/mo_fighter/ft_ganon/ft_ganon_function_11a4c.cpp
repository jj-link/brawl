#include <types.h>
#pragma force_active on

extern "C" const float lbl_109_rodata_48;

// The float constant is stored twice and reloaded as two words,
// returned as a u64 in the r3/r4 register pair.
union Pair {
    struct { float a, b; } f;
    u64 packed;
};

extern "C" u64 fn_109_11A4C(void) {
    Pair r;
    r.f.a = lbl_109_rodata_48;
    r.f.b = lbl_109_rodata_48;
    return r.packed;
}
