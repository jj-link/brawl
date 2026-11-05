#include <revolution/types.h>
#pragma force_active on

extern s32 fn_803B40F8(s32, s32, s32 *, s32, s32, s32 *, s32);
extern u16 fn_803A9C60(s32 *);

s32 fn_803B555C(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 *arg5, s32 arg6) {
    s32 result;

    if (arg1 == 0) {
        return 0xA;
    }
    if (*arg2 == 0) {
        return 0xA;
    }
    if (fn_803A9C60(arg2) == 0) {
        return 0xA;
    }
    if (arg5 == NULL) {
        return 0xA;
    }
    *arg5 = 0;
    if (arg3 & arg4) {
        return 0xA;
    }
    result = fn_803B40F8(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    return result & ((-result | result) >> 31);
}