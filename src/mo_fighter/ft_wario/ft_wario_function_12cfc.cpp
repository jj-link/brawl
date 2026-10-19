#include <types.h>
#pragma force_active on

extern "C" const float lbl_110_rodata_88;

// Two float copies of the same rodata value, returned as one 8-byte value in r3/r4.
union WarioInputPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_110_12CFC() {
    WarioInputPair result;
    result.stick.x = lbl_110_rodata_88;
    result.stick.y = lbl_110_rodata_88;
    return result.packed;
}
