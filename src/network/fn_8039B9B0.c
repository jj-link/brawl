#include <types.h>
#pragma force_active on
extern s32 fn_8039CDB4(void);
extern void fn_80397DE0(s32, char *, ...);
extern s32 fn_8039832C(s32, s32, u32);
extern char lbl_80491D28[];
extern char lbl_80491D3C[];
extern s32 lbl_805A1170;
s32 fn_8039B9B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    s32 temp;
    result = fn_8039CDB4();
    if (result != 0)
        return result;
    temp = lbl_805A1170 + 0x800;
    switch (arg0) {
    case 0:
        fn_80397DE0(temp, lbl_80491D28, arg1);
        goto success;
    case 1:
        fn_80397DE0(temp, lbl_80491D3C, arg1);
        goto success;
    default:
        result = -3;
        goto check;
    }
success:
    result = 0;
check:
    if (result != 0)
        return result;
    return fn_8039832C(arg2, temp, 0x10A);
}