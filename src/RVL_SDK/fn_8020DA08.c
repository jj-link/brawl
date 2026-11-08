#include <types.h>
#pragma force_active on

extern char *fn_8020D7B0(void);
extern s32 fn_8020CAEC(void);
extern s32 fn_80214A98(char *, u32 *, u32 *);
extern s32 fn_8020D844(u32 *, u32 *, char *);
extern char lbl_8047C290[];

s32 fn_8020DA08(u32 *arg0, u32 *arg1) {
    u32 sp14 = -1;
    u32 sp10 = -1;
    u32 spC = -1;
    u32 sp8 = -1;
    u32 a, b, c, d;

    if (fn_80214A98(fn_8020D7B0(), &spC, &sp8) != 0) {
        fn_8020CAEC();
    }
    sp8 = sp8 - 1;
    if (fn_8020D844(&sp14, &sp10, lbl_8047C290) != 0) {
        fn_8020CAEC();
    }
    a = (sp14 > 0x4400) ? 0 : 0x4400 - sp14;
    b = (sp10 > 0xFA0) ? 0 : 0xFA0 - sp10;
    c = (spC > 0x400) ? 0 : 0x400 - spC;
    d = (sp8 > 0x20) ? 0 : 0x20 - sp8;
    if (a < c) {
        c = a;
    }
    *arg0 = c;
    if (b < d) {
        d = b;
    }
    *arg1 = d;
    return 0;
}
