#include <types.h>
#pragma force_active on

extern "C" const float lbl_72_rodata_40;

// The module's eight-byte return value is packed in the r3/r4 register pair.
union GreenhillPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_72_40B4() {
    GreenhillPair result;
    result.stick.x = lbl_72_rodata_40;
    result.stick.y = lbl_72_rodata_40;
    return result.packed;
}
