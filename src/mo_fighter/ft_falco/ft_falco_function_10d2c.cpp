#include <types.h>
#pragma force_active on

extern "C" const float lbl_108_rodata_20;

// The module's eight-byte input values are returned in the r3/r4 register pair.
union FalcoInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_108_10D2C(void*) {
    FalcoInputPair result;
    result.stick.x = lbl_108_rodata_20;
    result.stick.y = lbl_108_rodata_20;
    return result.packed;
}
