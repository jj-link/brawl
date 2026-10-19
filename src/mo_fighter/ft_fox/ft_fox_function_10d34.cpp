#include <types.h>
#pragma force_active on

extern "C" const float lbl_97_rodata_1C;

union FoxInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_97_10D34(void) {
    FoxInputPair result;
    result.stick.x = lbl_97_rodata_1C;
    result.stick.y = lbl_97_rodata_1C;
    return result.packed;
}
