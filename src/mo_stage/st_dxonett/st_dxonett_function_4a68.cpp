#include <types.h>
#pragma force_active on

extern "C" const float lbl_78_rodata_A8;

union Pair64 {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_78_4A68(void) {
    Pair64 result;
    result.stick.x = lbl_78_rodata_A8;
    result.stick.y = lbl_78_rodata_A8;
    return result.packed;
}
