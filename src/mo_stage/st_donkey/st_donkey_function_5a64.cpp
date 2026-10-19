#include <types.h>
#pragma force_active on

extern "C" const float lbl_50_rodata_A0;

// The two float stores are reloaded as integer words and returned in the r3/r4 pair.
union DonkeyFloatPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_50_5A64() {
    DonkeyFloatPair result;
    result.stick.x = lbl_50_rodata_A0;
    result.stick.y = lbl_50_rodata_A0;
    return result.packed;
}
