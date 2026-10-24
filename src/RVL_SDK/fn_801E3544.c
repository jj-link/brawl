#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern u32 fn_8020AB58(void *, u32 *, u32);
extern s32 fn_8020BA48(char *, void *, s32);
extern s32 fn_8020BC3C(void *);
extern char lbl_80474DA8[];

s32 fn_801E3544(u32 *arg0) {
    u8 sp8[0x90];
    u32 sum = 0;
    u32 *p = arg0 + 1;
    s32 i;

    for (i = 0; i < 0x407; i++) {
        sum += *p++;
    }
    *arg0 = sum;

    if (fn_8020BA48(lbl_80474DA8, sp8, 2) == 0) {
        if (fn_8020AB58(sp8, arg0, 0x1020) != 0x1020U) {
            fn_8020BC3C(sp8);
            return 0;
        }
        return fn_8020BC3C(sp8) == 0;
    }
    return 0;
}
