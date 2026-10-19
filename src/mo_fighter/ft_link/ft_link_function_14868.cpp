#include <types.h>
#pragma force_active on

extern "C" const float lbl_93_rodata_80;

union FtLinkInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_93_14868(void) {
    FtLinkInputPair result;
    result.stick.x = lbl_93_rodata_80;
    result.stick.y = lbl_93_rodata_80;
    return result.packed;
}
