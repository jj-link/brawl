#include <types.h>
#pragma force_active on

extern "C" const float lbl_97_rodata_1C;

// Two float zeros are stored to the stack and reloaded as an integer pair (r3/r4).
union FoxFloatPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_97_10D58() {
    FoxFloatPair result;
    result.stick.x = lbl_97_rodata_1C;
    result.stick.y = lbl_97_rodata_1C;
    return result.packed;
}
