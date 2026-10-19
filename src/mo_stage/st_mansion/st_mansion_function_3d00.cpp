#include <types.h>
#pragma force_active on

extern "C" const float lbl_47_rodata_48;

// Returns the same float stored into both halves of an 8-byte value (r3/r4 pair).
union StPair {
    struct { float x, y; } f;
    struct { u32 first, second; } w;
    u64 packed;
};

extern "C" u64 fn_47_3D00(void) {
    StPair result;
    result.f.x = lbl_47_rodata_48;
    result.f.y = lbl_47_rodata_48;
    return result.packed;
}
