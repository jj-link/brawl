#include <types.h>
#pragma force_active on

extern "C" const float lbl_76_rodata_4C;

// The two float values are returned as a 64-bit pair in the r3/r4 registers.
union St_DxyPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_76_3000(void*) {
    St_DxyPair result;
    result.stick.x = lbl_76_rodata_4C;
    result.stick.y = lbl_76_rodata_4C;
    return result.packed;
}
