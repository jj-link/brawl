#include <types.h>
#pragma force_active on

extern "C" const float lbl_48_rodata_40;

// The two float values are returned as a packed 64-bit value in the r3/r4 pair.
union Pair48 {
    struct { float x, y; } f;
    struct { u32 a, b; } w;
    u64 packed;
};

extern "C" u64 fn_48_39C8(void) {
    Pair48 result;
    result.f.x = lbl_48_rodata_40;
    result.f.y = lbl_48_rodata_40;
    return result.packed;
}
