#include <types.h>
#pragma force_active on

extern s32 fn_8035D654(u8 *);
extern void fn_8035D774(s32);
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

s32 fn_8037ED38(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    void *temp_r3;
    s32 temp_r0;
    s32 temp_r3_2;

    if (arg0 == NULL || (s8) *arg0 == 0) {
        return -1;
    }
    if (arg2 == 0) {
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
    *(s32 *)((u8 *)temp_r3 + 0xC) = 4;
    temp_r3_2 = fn_8035D654(arg0);
    *(s32 *)((u8 *)temp_r3 + 0x14) = temp_r3_2;
    if (temp_r3_2 == 0) {
        fn_8037C5AC(temp_r3);
        return -1;
    }
    if (arg1 != NULL && (s8) *arg1 != 0) {
        s32 temp = fn_8035D654(arg1);
        *(s32 *)((u8 *)temp_r3 + 0x2C) = temp;
        if (temp == 0) {
            fn_8037C5AC(temp_r3);
            return -1;
        }
    }
    *(s32 *)((u8 *)temp_r3 + 0x160) = arg2;
    *(s32 *)((u8 *)temp_r3 + 0x34) = arg4;
    *(s32 *)((u8 *)temp_r3 + 0x40) = arg5;
    *(s32 *)((u8 *)temp_r3 + 0x44) = arg6;
    *(s32 *)((u8 *)temp_r3 + 0x48) = arg7;
    *(s32 *)((u8 *)temp_r3 + 0x158) = arg3;
    if (arg2 != 0) {
        if (fn_8037F894(temp_r3) == 0) {
            fn_8037C5AC(temp_r3);
            return -1;
        }
    }
    if (arg4 != 0) {
        while (fn_8037E8B4(temp_r3) == 0) {
            fn_8035D774(0xA);
        }
        return 0;
    }
    return *(s32 *)((u8 *)temp_r3 + 0x4);
}
