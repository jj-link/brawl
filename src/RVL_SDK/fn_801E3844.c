#include <types.h>
#pragma force_active on

s32 fn_801E369C(void* out);

typedef struct {
    u8 pad[0x18];
    s32 hi;
    s32 lo;
} Out;

s64 fn_801E3844(void) {
    Out sp8;
    s32 var_r31 = 0;
    s32 var_r30 = 0;
    if (*(u8*)0x80003186 != 0 && fn_801E369C(&sp8) != 0) {
        var_r31 = sp8.hi;
        var_r30 = sp8.lo;
    }
    return ((s64)var_r31 << 32) | (u32)var_r30;
}
