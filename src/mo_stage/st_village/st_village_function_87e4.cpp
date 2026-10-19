#include <types.h>
#pragma force_active on

extern "C" const float lbl_70_rodata_E8;

union Pair87E4 {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_70_87E4() {
    Pair87E4 result;
    result.stick.x = lbl_70_rodata_E8;
    result.stick.y = lbl_70_rodata_E8;
    return result.packed;
}
