#include <types.h>
#pragma force_active on

extern "C" const float lbl_51_rodata_8C;

union Fn51Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_51_5584(void) {
    Fn51Pair result;
    result.stick.x = lbl_51_rodata_8C;
    result.stick.y = lbl_51_rodata_8C;
    return result.packed;
}
