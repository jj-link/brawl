#include <types.h>
#pragma force_active on

extern "C" const float lbl_104_rodata_98;

union FloatPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_104_12A04(void) {
    FloatPair result;
    result.stick.x = lbl_104_rodata_98;
    result.stick.y = lbl_104_rodata_98;
    return result.packed;
}
