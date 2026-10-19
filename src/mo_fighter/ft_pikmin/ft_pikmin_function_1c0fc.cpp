#include <types.h>
#pragma force_active on

extern "C" const float lbl_113_rodata_64;

union PikminPair {
    struct { float x, y; } f;
    struct { u32 first, second; } w;
    u64 packed;
};

extern "C" u64 fn_113_1C0FC(void) {
    PikminPair result;
    result.f.x = lbl_113_rodata_64;
    result.f.y = lbl_113_rodata_64;
    return result.packed;
}
