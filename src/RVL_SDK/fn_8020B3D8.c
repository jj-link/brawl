#include <types.h>
#pragma force_active on
extern void fn_8020CC4C(s32 *, s32);
extern s32 fn_8020CA7C(const char *);
extern void fn_8020B2F8(u8 *, unsigned long, unsigned long, unsigned long);
extern s32 fn_80214560(s32 *, u8 *, u8 *, s32 *, s32 *, s32 *, s32 *);
extern s32 fn_802146B8(s32 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, void (*)(void), u8 *);
extern void fn_8020B52C(void);
s32 fn_8020B3D8(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    s32 locals[20];
    s32 result;
    locals[4] = 0;
    locals[5] = 0;
    locals[6] = 0;
    locals[7] = 0;
    locals[8] = 0;
    locals[9] = 0;
    locals[10] = 0;
    locals[11] = 0;
    locals[12] = 0;
    locals[13] = 0;
    locals[14] = 0;
    locals[15] = 0;
    locals[16] = 0;
    locals[17] = 0;
    locals[18] = 0;
    locals[19] = 0;
    fn_8020CC4C(&locals[4], arg0);
    if (arg4 == 0 && fn_8020CA7C((const char *)&locals[4]) != 0) return -0x66;
    if (arg3 != 0) {
        return fn_802146B8(&locals[4], arg1, arg1 + 4, arg2 + 0x20, arg2 + 0x24, arg2 + 0x28, arg2 + 0x2c, fn_8020B52C, arg2);
    }
    locals[3] = 0;
    locals[2] = 0;
    locals[1] = 0;
    locals[0] = 0;
    result = fn_80214560(&locals[4], arg1, arg1 + 4, &locals[3], &locals[2], &locals[1], &locals[0]);
    if (result == 0) {
        fn_8020B2F8(arg1 + 7, (unsigned long)locals[2], (unsigned long)locals[1], (unsigned long)locals[0]);
        arg1[6] = (u8)locals[3];
    }
    return result;
}