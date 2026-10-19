#include <types.h>
#pragma force_active on

extern "C" const float lbl_68_rodata_88;

// The two float halves are returned in the r3/r4 register pair.
union FloatPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_68_5A80(void) {
    FloatPair result;
    result.stick.x = lbl_68_rodata_88;
    result.stick.y = lbl_68_rodata_88;
    return result.packed;
}
