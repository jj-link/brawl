#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void *fn_8022EE58(u16 size);
extern void fn_8022F0E0(void *p);
extern void fn_802319FC(u32 a, void *b, u32 c);
extern u8 fn_8023CEFC(u8 a, void *b);
extern void fn_8023D478(s32 a);
extern u8 fn_802448BC(void *a, u8 b, u8 c);
extern u8 fn_802449C4(u16 a, u16 b, void *c, u8 d, u8 e);
extern void *memset(void *p, s32 c, u32 n);
extern char lbl_80529CF8[];
extern char lbl_80481110[];
extern u32 lbl_805A3A88;
extern u32 lbl_805A3A8C;

void fn_8023CFE0(u8 *arg0)
{
    u8 *base = (u8 *)lbl_80529CF8;
    u8 *b;
    void *ptr;
    void (*cb)(u8 *);
    u8 sp8;
    u8 st;
    u8 tmp;
    u8 max;
    void *p;

    cb = *(void (**)(u8 *))(base + 0x16B8);
    if (base[0x1845] != 0) {
        base[0x1845] = base[0x1845] - 1;
        return;
    }
    if (base[0x1844] != 1) {
        return;
    }
    if (*arg0 != 0) {
        if (base[0x27C0] >= 2) {
            fn_802319FC(0xD0001, lbl_80481110, *arg0);
        }
        sp8 = 10;
    } else {
        sp8 = 0;
    }
    st = base[0x1847];
    if (st == 0) {
        base[0x1844] = 0;
        if (cb != 0) {
            cb(&sp8);
        }
        return;
    }
    if (sp8 != 0) {
        fn_8023D478(10);
        base[0x1844] = 0;
        base[0x1848] = 0;
        base[0x1847] = 0;
        return;
    }
    if (st == 1) {
        tmp = fn_8023CEFC(base[0x1837], base + 0x1838);
        sp8 = tmp;
        if (tmp == 1) {
            base[0x1847] = 2;
            return;
        }
        base[0x1844] = 0;
        fn_8023D478(10);
        return;
    }
    max = base[0x1836];
    base[0x1847] = 3;
    base[0x1844] = 0;
    base[0x1836] = (max <= 12) ? max : 12;
    if (base[0x1848] & 1) {
        ptr = &lbl_805A3A8C;
    } else {
        ptr = &lbl_805A3A88;
    }
    if (base[0x1848] & 4) {
        if (fn_802449C4(*(u16 *)(base + 0x1842), *(u16 *)(base + 0x1840),
                        ptr, base[0x1835], base[0x1836]) == 0) {
            fn_8023D478(3);
        }
    } else {
        b = (u8 *)lbl_80529CF8;
        if (*(void **)(b + 0x16DC) != 0) {
            fn_8022F0E0(*(void **)(b + 0x16DC));
            *(void **)(b + 0x16DC) = 0;
        }
        *(u16 *)(b + 0x16E0) = 0;
        *(u16 *)(b + 0x16E2) = 0;
        p = fn_8022EE58(0x708);
        *(void **)(base + 0x16DC) = p;
        if (p != 0) {
            *(u16 *)(base + 0x16E2) = 0x96;
            memset(p, 0, 0x708);
        }
        if (fn_802448BC(ptr, base[0x1835], 0) == 0) {
            fn_8023D478(3);
        }
    }
}
