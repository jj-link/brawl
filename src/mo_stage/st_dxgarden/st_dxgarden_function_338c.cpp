#include <types.h>
#pragma force_active on

extern "C" const float lbl_77_rodata_48;

// The two floats are returned as one 8-byte value in the r3/r4 register pair.
union Fn77Pair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_77_338C(void) {
    Fn77Pair result;
    result.stick.x = lbl_77_rodata_48;
    result.stick.y = lbl_77_rodata_48;
    return result.packed;
}
