#include <types.h>
#pragma force_active on

extern "C" const float lbl_94_rodata_90;

union FloatPair {
    struct { float x, y; } f;
    u64 packed;
};

extern "C" u64 fn_94_1DB30(void) {
    FloatPair result;
    result.f.x = lbl_94_rodata_90;
    result.f.y = lbl_94_rodata_90;
    return result.packed;
}
