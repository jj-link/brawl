#pragma force_active on
#include <types.h>

extern s32 fn_801E42E4(s32, void *, s32, s32, s32);
extern s32 fn_801E46FC(s32);
extern s32 fn_801E4D4C(s32, s32, s32);
extern s32 fn_801E4E7C(s32);
extern s32 fn_801E54E0(s32, s32, s32);
extern s32 fn_801E55DC(s32);

s32 fn_801E5DBC(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    u32 spC;
    s32 sp8;
    s32 err;
    u32 v;

    sp8 = arg2;
    switch (arg4) {
    case 1:
        spC = *arg3 << 24;
        break;
    case 2:
        v = *(u16 *)arg3;
        spC = (v << 24) | ((v << 8) & 0xFF0000);
        break;
    default:
        v = *(u32 *)arg3;
        spC = ((v << 24) | ((v << 8) & 0xFF0000)) | ((v >> 24) | ((v >> 8) & 0xFF00));
        break;
    }

    err = fn_801E54E0(arg0, arg1, 0) == 0;
    if (err) {
        return 0;
    }
    err |= fn_801E4D4C(arg0, arg1, 4) == 0;
    if (err) {
        fn_801E55DC(arg0);
        return 0;
    }
    err |= fn_801E42E4(arg0, &sp8, 4, 1, 0) == 0;
    err |= fn_801E46FC(arg0) == 0;
    err |= fn_801E42E4(arg0, &spC, 4, 1, 0) == 0;
    err |= fn_801E46FC(arg0) == 0;
    err |= fn_801E4E7C(arg0) == 0;
    err |= fn_801E55DC(arg0) == 0;
    return !err;
}
