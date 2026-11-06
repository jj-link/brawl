#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, u16, int, u8);
extern u8 lbl_8052CDC0[];
extern char lbl_80483DCC[];

void fn_8024EA24(u8 *self) {
    u8 *p;
    u8 v;

    v = (*(u8 **)(self + 0x10))[0x31] + 1;
    (*(u8 **)(self + 0x10))[0x31] = v;
    self[0x35] = v;
    p = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), 4, 2, v);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483DCC);
        }
    } else {
        p[0x14] = *(u16 *)(*(u8 **)(self + 0x30) + 2);
        p[0x15] = (int)*(u16 *)(*(u8 **)(self + 0x30) + 2) >> 8;
        p[0x16] = *(u16 *)(self + 0x14);
        p[0x17] = (int)*(u16 *)(self + 0x14) >> 8;
        fn_8024CB94(*(u8 **)(self + 0x10), 0, p);
    }
}
