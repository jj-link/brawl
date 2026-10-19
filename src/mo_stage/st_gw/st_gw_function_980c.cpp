#include <types.h>
#pragma force_active on

extern "C" const float lbl_63_rodata_A8;

union St96Pair {
    struct { float x, y; } f;
    struct { u32 first, second; } w;
    u64 packed;
};

extern "C" u64 fn_63_980C(void) {
    St96Pair result;
    result.f.x = lbl_63_rodata_A8;
    result.f.y = lbl_63_rodata_A8;
    return result.packed;
}
