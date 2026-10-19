#include <types.h>
#pragma force_active on

extern "C" const float lbl_73_rodata_78;

// The two float values are returned packed in the r3/r4 register pair.
union Pair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_73_9728(void) {
    Pair result;
    result.stick.x = lbl_73_rodata_78;
    result.stick.y = lbl_73_rodata_78;
    return result.packed;
}
