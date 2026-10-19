#include <types.h>
#pragma force_active on

extern "C" const float lbl_57_rodata_260;

union Fn57Pair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_57_A49C() {
    Fn57Pair result;
    result.stick.x = lbl_57_rodata_260;
    result.stick.y = lbl_57_rodata_260;
    return result.packed;
}
