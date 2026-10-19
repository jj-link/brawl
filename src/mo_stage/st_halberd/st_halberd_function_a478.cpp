#include <types.h>
#pragma force_active on

extern "C" const float lbl_57_rodata_260;

union FloatPair {
    struct { float x, y; } f;
    u64 packed;
};

extern "C" u64 fn_57_A478() {
    FloatPair result;
    result.f.x = lbl_57_rodata_260;
    result.f.y = lbl_57_rodata_260;
    return result.packed;
}
