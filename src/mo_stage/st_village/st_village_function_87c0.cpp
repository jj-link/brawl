#include <types.h>
#pragma force_active on

extern "C" const float lbl_70_rodata_E8;

// The function's eight-byte return value is returned in the r3/r4 register pair.
union Fn70Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_70_87C0() {
    Fn70Pair result;
    result.stick.x = lbl_70_rodata_E8;
    result.stick.y = lbl_70_rodata_E8;
    return result.packed;
}
