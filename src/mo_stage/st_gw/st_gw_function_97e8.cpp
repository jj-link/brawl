#include <types.h>
#pragma force_active on

extern "C" const float lbl_63_rodata_A8;

union StGwFloatPair {
    struct { float a, b; } f;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_63_97E8(void) {
    StGwFloatPair result;
    result.f.a = lbl_63_rodata_A8;
    result.f.b = lbl_63_rodata_A8;
    return result.packed;
}
