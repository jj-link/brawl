#include <types.h>
#pragma force_active on

extern "C" const float lbl_110_rodata_88;

union WarioPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_110_12D20() {
    WarioPair result;
    result.stick.x = lbl_110_rodata_88;
    result.stick.y = lbl_110_rodata_88;
    return result.packed;
}
