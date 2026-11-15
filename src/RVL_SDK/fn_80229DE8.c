#include <types.h>
#pragma force_active on

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern s32 fn_8020E18C(void);
extern s32 fn_8020FDF4(u8 *);
extern void fn_8022E928(const char *, ...);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);
extern char lbl_8047EAC4[];
extern u8 lbl_804FB4A0[];
extern u8 lbl_804FBD58[];

s32 fn_80229DE8(void) {
    s32 r;
    s32 en;
    u8 saved;
    s32 off;
    s32 idx;
    u8 *base;
    u8 **list;

    r = fn_8020E18C();
    if ((((1U - (u32)r) | ((u32)r - 1U)) >> 31) == 0) {
        return 0x16;
    }

    memset(lbl_804FBD58 + 1, 0, 0x2BC);
    en = OSDisableInterrupts();
    base = lbl_804FB4A0;
    saved = base[0x12];
    OSRestoreInterrupts();
    lbl_804FBD58[0] = saved;

    idx = 0;
    list = *(u8 ***)(base + 0x64);
    while (list != 0) {
        off = (s32)(u8)idx * 0x46;
        memcpy(lbl_804FBD58 + 1 + off, *list + 0x40, 6);
        memcpy(lbl_804FBD58 + 7 + off, *list, 0x40);
        list = (u8 **)list[2];
        idx++;
    }

    fn_8022E928(lbl_8047EAC4, (u8)idx);
    if (fn_8020FDF4(lbl_804FBD58) != 0) {
        return 0x19;
    }
    return 0x16;
}
