#include <types.h>
#pragma force_active on

extern "C" const float lbl_72_rodata_40;

union GreenhillPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_72_40D8() {
    GreenhillPair result;
    result.stick.x = lbl_72_rodata_40;
    result.stick.y = lbl_72_rodata_40;
    return result.packed;
}
