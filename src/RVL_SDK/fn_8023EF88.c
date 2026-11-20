#include <types.h>
#pragma force_active on

extern char lbl_804811C8[];
extern char lbl_80529CF8[];

extern void fn_802319FC(s32, const char *, u16);
extern void fn_80231A14(s32, const char *, u16, u16);
extern void fn_80231A74(s32, const char *, s32, s32, u16, u16, u8, u16);
extern u8 fn_802451F8(u16, u32);
extern u8 fn_8024567C(u16, s32, s32, u16, u16, u8, u16);

s32 fn_8023EF88(u16 arg0, char *arg1) {
    u16 v;
    char *p = arg1;
    char *base;
    char *label = lbl_804811C8;
    char *buf;

    if (arg0 >= 3 || (base = lbl_80529CF8 + arg0 * 0x34 + 0x1854, *(u16 *)(base + 8) != 4)) {
        return 6;
    }
    buf = base + 0x14;
    if ((u8)base[0x2E] == 0 || (u8)lbl_80529CF8[0x1908] == 0) {
        *(u16 *)(buf + 0xC) = *(u16 *)(p + 2) & (*(u16 *)(lbl_80529CF8 + 0x656) & 7);
        if ((u8)lbl_80529CF8[0x27C0] >= 3) {
            fn_80231A14(0xD0002, label + 0x248, *(u16 *)(base + 0xA),
                        *(u16 *)(buf + 0xC));
        }
        if (fn_802451F8(*(u16 *)(base + 0xA),
                        (*(u16 *)(buf + 0xC) << 5) & 0xE0) == 0) {
            return 3;
        }
    } else {
        v = *(u16 *)(p + 2) & *(u16 *)(lbl_80529CF8 + 0x656) & 0x3F;
        if ((u8)lbl_80529CF8[0x636] >= 3) {
            v |= (*(u16 *)(p + 2) | *(u16 *)(lbl_80529CF8 + 0x656)) & 0x3C0;
        }
        if ((u8)lbl_80529CF8[0x27C0] >= 3) {
            fn_802319FC(0xD0002, label + 0x28C, *(u16 *)(base + 0xA));
        }
        if ((u8)lbl_80529CF8[0x27C0] >= 3) {
            fn_80231A74(0xD0002, label + 0x8C, *(s32 *)buf, *(s32 *)(buf + 4),
                        *(u16 *)p, *(u16 *)(buf + 0xA), (u8)p[4], v);
        }
        if (fn_8024567C(*(u16 *)(base + 0xA), *(s32 *)buf, *(s32 *)(buf + 4),
                        *(u16 *)p, *(u16 *)(buf + 0xA), (u8)p[4], v) == 0) {
            return 3;
        }
        *(u16 *)(p + 2) = v;
    }
    return 1;
}