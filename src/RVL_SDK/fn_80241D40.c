#include <types.h>
#pragma force_active on

extern u8 lbl_804814C8[];
extern u8 lbl_80529CF8[];
extern u8 lbl_8052CDC0[];

extern void fn_802319E4(u32, const char *);
extern void fn_80231A14(u32, const char *, u32, u32);
extern void fn_80231A2C(u32, const char *, u32, u32, u32);
extern u8 fn_8023D57C(void *, void *, u32, u32, u32);
extern s32 fn_80242120(void *);
extern u8 fn_80245288(u16);
extern u8 fn_80245304(u16, u32);
extern s32 fn_8024E568(void *);
extern u8 fn_802500CC(void);

static inline int start_second(u8 *p) {
    if (fn_80245304(*(u16 *)(p + 0x18), 1) == 0) {
        return 0;
    }
    p[0x7F] = 2;
    return 1;
}

static inline int all_set(u8 *p) {
    int i;
    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x10))[i] != 0xFFFFFFFFU) return 0;
    }
    return 1;
}

s32 fn_80241D40(void *arg0) {
    u8 *base = lbl_804814C8;
    u8 *p = (u8 *)arg0;
    u8 r29;
    u8 r3;
    u8 f;
    s32 ok;

    if (lbl_80529CF8[0x27C0] >= 4U) {
        fn_80231A2C(0xD0003, (const char *)(base + 0x8AC), p[0x81], p[0x76], p[0x7F]);
    }
    if (p[0x7F] != 0) {
        return 1;
    }
    if (*(u16 *)(p + 0x18) == 0xFFFF) {
        if (fn_8024E568(p + 0x1C) == 0) {
            if (lbl_8052CDC0[0] >= 2U) {
                fn_802319E4(0x80001, (const char *)(base + 0x8EC));
            }
            return 3;
        }
        if (fn_802500CC() == 0) {
            return 3;
        }
        p[0x80] = 1;
        return 1;
    }
    if (!(p[0x76] & 8) && *(u16 *)(p + 0x18) != 0xFFFF) {
        if (lbl_80529CF8[0x27C0] >= 4U) {
            fn_802319E4(0xD0003, (const char *)(base + 0x910));
        }
        r29 = p[0x7F];
        p[0x7F] = 3;
        if (fn_8023D57C(p + 0x1C, 0, 2, 0x1E, 0) != 1) {
            p[0x7F] = r29;
            ok = 0;
        } else {
            ok = 1;
        }
        if (ok != 0) {
            return 1;
        }
        p[0x76] |= 8;
    }

    f = p[0x76];
    if (!(f & 2) &&
        ((p[0x80] != 0 && (p[0x81] & 0x10)) || (p[0x80] == 0 && (p[0x81] & 2))) &&
        *(u16 *)(p + 0x18) != 0xFFFF) {
        if (lbl_80529CF8[0x27C0] >= 4U) {
            fn_802319E4(0xD0003, (const char *)(base + 0x934));
        }
        p[0x7F] = 1;
        if (fn_80245288(*(u16 *)(p + 0x18)) == 0) {
            return 3;
        }
        return 1;
    }
    if (!(f & 4) &&
        ((p[0x80] != 0 && (p[0x81] & 0x20)) || (p[0x80] == 0 && (p[0x81] & 4))) &&
        *(u16 *)(p + 0x18) != 0xFFFF) {
        if (lbl_80529CF8[0x27C0] >= 4U) {
            fn_802319E4(0xD0003, (const char *)(base + 0x95C));
        }
        if (start_second(p) == 0) {
            return 3;
        }
        return 1;
    }
    if (!(f & 1) &&
        ((p[0x80] != 0 && (p[0x81] & 8)) || (p[0x80] == 0 && (p[0x81] & 1)))) {
        if (!all_set(p)) {
            u8 *obj = *(u8 **)p;
            u8 t = obj[0xF];
            if (t < 0x2E && !((1U << (t & 0x1F)) & *(u32 *)(p + ((t >> 3) & 0x1C) + 0x10))) {
                if (lbl_80529CF8[0x27C0] >= 4U) {
                    fn_802319E4(0xD0003, (const char *)(base + 0x980));
                }
                return fn_80242120(p);
            }
        }
    }
    p[0x81] &= 0xC0;
    if (lbl_80529CF8[0x27C0] >= 4U) {
        fn_80231A14(0xD0003, (const char *)(base + 0x9A8), *(u32 *)(p + 0x14), *(u32 *)(p + 0x10));
    }
    if (lbl_80529CF8[0x27C0] >= 4U) {
        fn_802319E4(0xD0003, (const char *)(base + 0x9D0));
    }
    return 0;
}