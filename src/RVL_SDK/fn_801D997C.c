#include <types.h>
#include <revolution/DVD/dvd.h>
#include <stdio.h>
#pragma force_active on

extern u8 fn_801D6620(void);
extern s32 fn_801D536C(void);
extern s32 fn_8020D38C(char *dst);
extern s32 fn_8020B5A0(char *src, u8 *buf);
extern char lbl_80467A80[];

s32 fn_801D997C(u64 id, s32 arg2) {
    char sp54[0x44];
    char sp10[0x44];
    u8 sp8[8];
    u16 var_r0;
    u16 var_r31;

    if (fn_8020D38C(sp54) != 0) {
        return 0;
    }
    if (fn_8020B5A0(sp54, sp8) != 0) {
        return 0;
    }

    var_r31 = *(u16 *)(sp8 + 4);
    if (var_r31 == 2 && fn_801D6620() == 0x80 &&
        (fn_801D536C() & 0xF0000000) == 0x10000000) {
        var_r31 = *(u16 *)DVDGetCurrentDiskID()->company;
    }

    if (arg2 != 0) {
        var_r0 = *(u16 *)DVDGetCurrentDiskID()->company;
    } else {
        sprintf(sp10, lbl_80467A80, (u32)((id >> 32) & 0xFFFFFFFF), (u32)(id & 0xFFFFFFFF));
        if (fn_8020B5A0(sp10, sp8) != 0) {
            return 0;
        }
        var_r0 = *(u16 *)(sp8 + 4);
    }

    return var_r31 == var_r0;
}
