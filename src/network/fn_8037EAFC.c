#include <types.h>
#pragma force_active on

extern s32 fn_8035D654(u8 *);
extern void fn_8035D774(s32);
extern s32 fn_8037B3FC(void *, void *, s32, s32);
extern s32 fn_8037B4F8(void *, void *, s32, s32);
extern void fn_8037BE6C(void);
extern void fn_8037BE74(void);
extern void fn_8037BE78(void);
extern void *fn_8037C3E8(void);
extern void fn_8037C5AC(void *);
extern s32 fn_8037E8B4(void *);
extern s32 fn_8037F894(void *);
extern s32 lbl_8059FA50;
extern s32 lbl_8059FA54;
extern s32 lbl_805A1078;

s32 fn_8037EAFC(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    void *temp_r3;
    s32 temp_r0;
    s32 temp_r3_2;
    s32 temp;
    s32 var_r3;
    u32 flag;

    if (arg0 == NULL || (s8) *arg0 == 0) {
        return -1;
    }
    if (arg3 < 0) {
        return -1;
    }
    if (arg2 != 0 && arg3 == 0) {
        return -1;
    }
    if (lbl_805A1078 == 0) {
        fn_8037BE74();
        temp_r0 = lbl_805A1078 + 1;
        lbl_805A1078 = temp_r0;
        if (temp_r0 == 1) {
            fn_8037BE6C();
            lbl_8059FA50 = 0x7d;
            lbl_8059FA54 = 0xfa;
        } else {
            fn_8037BE78();
        }
    }
    temp_r3 = fn_8037C3E8();
    if (temp_r3 == NULL) {
        return -1;
    }
    *(s32 *)((u8 *)temp_r3 + 0xC) = 0;
    temp_r3_2 = fn_8035D654(arg0);
    *(s32 *)((u8 *)temp_r3 + 0x14) = temp_r3_2;
    if (temp_r3_2 == 0) {
        fn_8037C5AC(temp_r3);
        return -1;
    }
    if (arg1 != NULL && (s8) *arg1 != 0) {
        temp = fn_8035D654(arg1);
        *(s32 *)((u8 *)temp_r3 + 0x2C) = temp;
        if (temp == 0) {
            fn_8037C5AC(temp_r3);
            return -1;
        }
    }
    *(s32 *)((u8 *)temp_r3 + 0x160) = arg4;
    flag = (u32)(-arg2 | arg2) >> 31;
    *(s32 *)((u8 *)temp_r3 + 0x34) = arg6;
    *(s32 *)((u8 *)temp_r3 + 0x40) = arg7;
    *(s32 *)((u8 *)temp_r3 + 0x44) = arg8;
    *(s32 *)((u8 *)temp_r3 + 0x48) = arg9;
    *(s32 *)((u8 *)temp_r3 + 0x158) = arg5;
    *(u32 *)((u8 *)temp_r3 + 0x108) = flag;
    if (flag != 0) {
        var_r3 = fn_8037B4F8(temp_r3, (u8 *)temp_r3 + 0xE4, arg2, arg3);
    } else {
        var_r3 = fn_8037B3FC(temp_r3, (u8 *)temp_r3 + 0xE4, 0x800, 0x800);
    }
    if (var_r3 == 0) {
        fn_8037C5AC(temp_r3);
        return -1;
    }
    if (arg4 != 0) {
        if (fn_8037F894(temp_r3) == 0) {
            fn_8037C5AC(temp_r3);
            return -1;
        }
    }
    if (arg6 != 0) {
        while (fn_8037E8B4(temp_r3) == 0) {
            fn_8035D774(0xA);
        }
        return 0;
    }
    return *(s32 *)((u8 *)temp_r3 + 0x4);
}
