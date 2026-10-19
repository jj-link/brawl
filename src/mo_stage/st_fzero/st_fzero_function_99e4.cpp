#include <types.h>
#pragma force_active on

extern "C" const float lbl_61_rodata_118;

// The two float values are packed into an 8-byte value returned in the r3/r4 pair.
union St_61_Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_61_99E4(void) {
    St_61_Pair result;
    result.stick.x = lbl_61_rodata_118;
    result.stick.y = lbl_61_rodata_118;
    return result.packed;
}
