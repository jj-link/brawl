#include <types.h>
#pragma force_active on

extern "C" const float lbl_107_rodata_D8;

union GameWatchInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_107_16904() {
    GameWatchInputPair result;
    result.stick.x = lbl_107_rodata_D8;
    result.stick.y = lbl_107_rodata_D8;
    return result.packed;
}
