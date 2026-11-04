#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern char lbl_80529CF8[];
extern char lbl_80480BD8[];
extern void fn_80231A74(int, void *, int, int, int, int, int, int);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_80231FB0(void *, int, int);
extern void fn_80232020(void *);
extern u8 fn_80246940(u16);

static inline u8 *find_entry(const void *arg0) {
    u32 i;
    u8 *p;
    i = 0;
    p = (u8 *)lbl_80529CF8 + 0x34;
    while (i < 4) {
        if (p[0x119] != 0 && fn_803F6150(p + 8, arg0, 6) == 0) {
            return p;
        }
        i++;
        p += 0x11C;
    }
    return 0;
}

int fn_802395F8(u8 *arg0, int arg1) {
    u8 *p;
    if ((u8)lbl_80529CF8[0x27C0] >= 3U) {
        fn_80231A74(0xD0002, lbl_80480BD8,
            arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
    }
    if (*(int *)(lbl_80529CF8 + 0x5FC) != 0) {
        return 2;
    }
    p = find_entry(arg0);
    if (p != 0) {
        fn_80231FB0(lbl_80529CF8 + 0x5E4, 9, 3);
        *(int *)(lbl_80529CF8 + 0x5FC) = arg1;
        if (fn_80246940(*(u16 *)p) == 0) {
            fn_80232020(lbl_80529CF8 + 0x5E4);
            *(int *)(lbl_80529CF8 + 0x5FC) = 0;
            return 3;
        }
        return 1;
    }
    return 7;
}
