#include <types.h>
#pragma force_active on

extern "C" const float lbl_116_rodata_18;

// Two floats stored to the stack and reloaded as a 64-bit r3/r4 pair.
union PokeFloatPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_116_1158C(void) {
    PokeFloatPair result;
    result.stick.x = lbl_116_rodata_18;
    result.stick.y = lbl_116_rodata_18;
    return result.packed;
}
