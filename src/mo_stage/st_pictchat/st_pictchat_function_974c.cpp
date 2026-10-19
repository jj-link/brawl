#include <types.h>
#pragma force_active on

extern "C" const float lbl_73_rodata_78;

union Fn73Pair {
    float f[2];
    u32 w[2];
    u64 packed;
};

extern "C" u64 fn_73_974C() {
    Fn73Pair result;
    result.f[0] = lbl_73_rodata_78;
    result.f[1] = lbl_73_rodata_78;
    return result.packed;
}
