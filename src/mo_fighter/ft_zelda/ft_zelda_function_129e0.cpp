#include <types.h>
#pragma force_active on

extern "C" const float lbl_104_rodata_98;

// The 8-byte return value is returned in the r3/r4 register pair.
union ZeldaPairResult {
    struct { float x, y; } pair;
    u64 packed;
};

extern "C" u64 fn_104_129E0(void) {
    ZeldaPairResult result;
    result.pair.x = lbl_104_rodata_98;
    result.pair.y = lbl_104_rodata_98;
    return result.packed;
}
