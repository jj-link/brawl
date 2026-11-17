#include <types.h>
#pragma force_active on

extern s32 fn_803AB808(void);
extern s32 fn_803ABF18(s32, u8 *, s32, s32, u32, u32 *);
extern s32 fn_803AC504(s32, u8 *);
extern s32 fn_803AE0F4(s32, u8 *, s32 *);
extern s32 fn_803ADD50(u8 *, s32, u8 *);

s32 fn_803ADF24(s32 arg0, u8 *arg1) {
    u8 sp10[0x18];
    u8 sp28[0x200];
    u32 spC;
    s32 sp8;
    s32 r;
    s32 var_r31;
    u8 i;
    u8 *e;

    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }
    r = fn_803AB808();
    if (r != 0) {
        return r;
    }
    var_r31 = 0;
    for (i = 0; i < 4; i++) {
        if (((u8 *)((u32)arg1 + i * 0x14))[9] == 5 || ((u8 *)((u32)arg1 + i * 0x14))[9] == 0xF) {
            var_r31 = *(u32 *)(arg1 + 4) + *(u32 *)(arg1 + i * 0x14 + 0x14);
            break;
        }
    }
    if (i == 4) {
        return 7;
    }
    r = fn_803AC504(arg0, sp10);
    if (r != 0) {
        return r;
    }
    r = fn_803ABF18(arg0, sp28,
                    var_r31 * ((s32)*(u16 *)(sp10 + 8) >> 9),
                    1, 0x200, &spC);
    if (r != 0) {
        return r;
    }
    fn_803AE0F4(arg0, sp28, &sp8);
    if (sp8 != 0) {
        fn_803ADD50(sp28, var_r31, arg1);
    } else {
        return 6;
    }
    return 0;
}