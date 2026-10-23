#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_8001F0D4(s32*);

s32 fn_8001F084(s32 arg0) {
    s32 result = 0;
    struct {
        s32 val;
        s32 pad[4];
        u8 pad_a;
        u8 pad_b;
        u8 lo : 2;
        u8 hi : 6;
        u8 pad_c;
        s32 pad_d[2];
    } local;

    local.val = arg0;
    local.lo = 0;
    if (fn_8001F0D4(&local.val) == 0) {
        result = 1;
    }
    return result;
}
}
