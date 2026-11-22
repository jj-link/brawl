#include <types.h>
#pragma force_active on

extern char lbl_80529CF8[];
extern char lbl_80481188[];

extern s32 fn_80237F1C(u32);
extern void fn_80231A14(u32, const char *, u32, u16);
extern u8 fn_8023F2A4(void);
extern void fn_802451F8(u16, u16);
extern u8 fn_80245304(u32, u8);
extern u8 fn_80245BFC(void *, u8);
extern void *fn_8023A0F0(void *);
extern void fn_8023E048(u32, u32, u32);

void fn_8023E32C(u8 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    char *q;
    char *base;
    char *entry;
    s32 off;
    s32 idx;
    char *p;
    char *obj;

    idx = (u8)fn_80237F1C(arg1);
    if (idx < 4) {
        off = idx * 0x11C;
        base = lbl_80529CF8;
        entry = base + off;
        if (arg2 == 0 && *(u16 *)(entry + 0x38) != 0 && fn_8023F2A4() == 0) {
            *(u16 *)(entry + 0x38) = 0;
            if ((u8)base[0x27C0] >= 5) {
                fn_80231A14(0xD0004, lbl_80481188, arg1, *(u16 *)(entry + 0x36));
            }
            fn_802451F8(*(u16 *)(entry + 0x34), *(u16 *)(entry + 0x36));
        }

        p = lbl_80529CF8 + idx * 0x22;
        p[0x4EC] = arg2;
        *(s16 *)(p + 0x4EA) = arg3;
        {
            int j;
            char *slot = p + 0x4CC;
            for (j = 0; j < 2; j++, slot += 10) {
                if (arg2 == 0 && (u8)slot[8] == 1) {
                    slot[8] = 0;
                }
            }
        }
        if ((u8)p[0x4ED] == 1) {
            fn_8023E048(0x80, idx, 0);
        }

        q = lbl_80529CF8;
        for (idx = 0; idx < 2; idx++) {
            if (q[0x558] & 2) {
                (*(void (**)(void *, s32, s16, u8))(q + 0x554))(
                    entry + 0x3C, arg2, arg3, arg0);
            }
            q += 8;
        }

        p = (char *)((u32)lbl_80529CF8 + (u32)off);
        if ((u8)p[0x14F] == 1) {
            char *addr = p + 0x3C;
            obj = fn_8023A0F0(addr);
            if (obj != 0 && (obj[0x76] & 4)) {
                if (fn_80245304(arg1, 0) != 0) {
                    p[0x14F] = 2;
                    return;
                }
                goto block26;
            }

            if (fn_80245BFC(addr, (u8)((u8)lbl_80529CF8[off + 0x14E] == 0)) != 0) {
                p[0x14F] = 0;
                return;
            }

        block26:
            p[0x14F] = 0;
            {
                void (*cb)(char *) =
                    *(void (**)(char *))(lbl_80529CF8 + 0x62C);
                if (cb != 0) {
                    lbl_80529CF8[0x624] = arg0;
                    cb(lbl_80529CF8 + 0x624);
                    *(void **)(lbl_80529CF8 + 0x62C) = 0;
                }
            }
        }
    }
}
