#include <types.h>
#pragma force_active on

extern "C" const float lbl_121_rodata_80;

union ToonLinkFloatPair {
    struct { float x, y; } pair;
    u64 packed;
};

extern "C" u64 fn_121_148B4() {
    ToonLinkFloatPair result;
    result.pair.x = lbl_121_rodata_80;
    result.pair.y = lbl_121_rodata_80;
    return result.packed;
}
