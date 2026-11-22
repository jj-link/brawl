#pragma force_active on
#include <internal/mem.h>

extern char lbl_80529CF8[];
extern char lbl_804808F8[];
extern char lbl_80480938[];

extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_80231A74(int, void *, int, int, int, int, int, int);
extern void fn_802319FC(int, void *, int);
extern void fn_8023DC7C(int);
extern int fn_80245600(u16);
extern int fn_80245584(u32);
extern u8 *fn_8023A038(u32);
extern u8 fn_802451F8(u16, u16);
extern void fn_80245508(u16);
extern void fn_80238768(void *, void *);
extern void fn_802466F8(u16, u16);

typedef void (*Callback)(void *, void *, void *, void *, int);

static inline char *find_entry(void *addr)
{
    char *q = lbl_80529CF8 + 0x34;
    u32 i;

    for (i = 0; i < 4; i++, q += 0x11c) {
        if (*(u8 *)(q + 0x119) && fn_803F6150(q + 8, addr, 6) == 0)
            return q;
    }
    return 0;
}

void fn_80237FA0(u8 *a, void *b, void *c, u16 d, u8 e)
{
    u16 mask;
    char *p;
    char *q;
    u8 *info;
    u8 j;
    u16 value;
    Callback callback;

    q = find_entry(a);

    if (q) {
        *(u16 *)q = d;
        *(u8 *)(q + 0x11a) = e;
        if (*(u8 *)(lbl_80529CF8 + 0x27c0) >= 4)
            fn_80231A74(0xd0003, lbl_804808F8,
                        a[0], a[1], a[2], a[3], a[4], a[5]);
        return;
    }

    p = lbl_80529CF8 + 0x34;
    for (j = 0; j < 4; j++, p += 0x11c) {
        if (*(u8 *)(p + 0x119) == 0) {
            *(u8 *)(p + 0x119) = 1;
            *(u16 *)p = d;
            *(u8 *)(p + 0x11a) = e;
            *(u16 *)(p + 4) = 0;
            fn_8023DC7C(j);
            memcpy(p + 8, a, 6);
            if (b)
                memcpy(p + 0xe, b, 3);
            if (c)
                memcpy(p + 0x11, c, 0xf8);
            fn_80245600(*(u16 *)p);
            fn_80245584(*(u16 *)p);
            info = fn_8023A038(d);
            if (info) {
                u8 k;
                for (k = 0; k < 8; k++) {
                    if (info[0x77 + k]) {
                        u16 flags;
                        u16 masked;
                        u8 level;
                        memcpy(p + 0x110, info + 0x77, 8);
                        flags = *(u16 *)(lbl_80529CF8 + 0x654);
                        level = *(u8 *)(lbl_80529CF8 + 0x636);
                        masked = flags & 0xcc18;
                        if (level >= 3)
                            mask = masked | (flags & 0x3306);
                        else
                            mask = masked & ~0x3306;
                        if (*(u8 *)(lbl_80529CF8 + 0x27c0) >= 4)
                            fn_802319FC(0xd0003, lbl_80480938, mask);
                        if (fn_802451F8(*(u16 *)p, mask))
                            *(u16 *)(p + 2) = mask;
                        if (*(u16 *)(lbl_80529CF8 + 0x4c4))
                            fn_80238768(p + 8, lbl_80529CF8 + 0x4c4);
                        value = *(u16 *)(lbl_80529CF8 + 0x4c6);
                        q = find_entry(p + 8);
                        if (q) {
                            *(u16 *)(q + 0x10e) = value;
                            if (*(u8 *)(q + 0x11a) == 0)
                                fn_802466F8(*(u16 *)q, value);
                        }
                        callback = *(Callback *)(lbl_80529CF8 + 0x4c8);
                        if (callback)
                            callback(p + 8, p + 0xe, p + 0x11, p + 0x110, 1);
                        return;
                    }
                }
            }
            fn_80245508(*(u16 *)p);
            return;
        }
    }
}
