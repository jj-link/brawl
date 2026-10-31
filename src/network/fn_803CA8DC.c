#include <types.h>
#pragma force_active on

extern unsigned char lbl_8053A6E0[];
extern s32 fn_803C7EEC(s32, void *);
extern s32 fn_803C7E40(s32);
extern void fn_803C76B4(s32, s32 *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_803C7DE8(s32, s32);

s32 fn_803CA8DC(s32 arg0, s32 arg1, s32 *arg2) {
    s32 temp_r30;
    s32 temp_r31;
    s32 sp8;
    s32 spC;
    s32 sp10;

    temp_r30 = *(s32 *)(lbl_8053A6E0 + ((arg0 & 0xFF) * 0x34) + 0x1BC);
    temp_r31 = fn_803C7EEC(arg0, lbl_8053A6E0 + ((arg0 & 0xFF) * 0x34));
    sp8 = fn_803C7E40(arg0);
    spC = temp_r31;
    sp10 = 0xF0;
    fn_803C76B4(arg1, arg2, temp_r30, 1, 0x200, 0xEB, 0x90, 0x3F, sp8, spC, sp10);
    fn_803C7DE8(arg0, *arg2);
    return 0;
}
