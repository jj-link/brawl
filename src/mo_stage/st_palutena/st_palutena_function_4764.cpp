#include <types.h>
#pragma force_active on

extern "C" const float lbl_67_rodata_10;

union PalutenaFloatPair {
    struct { float x, y; } floats;
    u64 packed;
};

extern "C" u64 fn_67_4764() {
    PalutenaFloatPair result;
    result.floats.x = lbl_67_rodata_10;
    result.floats.y = lbl_67_rodata_10;
    return result.packed;
}
