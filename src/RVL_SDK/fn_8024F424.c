#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, u16, int, u8);
extern void fn_8022F500(void *, void *);
extern u8 lbl_8052CDC0[];
extern char lbl_80483DCC[];

void fn_8024F424(u8 *self) {
    u8 *p;
    u8 v;
    
    v = (*(u8**)(self + 0x10))[0x31] + 1;
    (*(u8**)(self + 0x10))[0x31] = v;
    self[0x35] = v;
    p = fn_8024E864(*(u16*)(*(u8**)(self + 0x10) + 0x28), 4, 6, v);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483DCC);
        }
    } else {
        p[0x14] = *(u16*)(self + 0x16);
        p[0x15] = *(u16*)(self + 0x16) >> 8;
        p[0x16] = *(u16*)(self + 0x14);
        p[0x17] = *(u16*)(self + 0x14) >> 8;
        *(u16*)(p + 6) = 0;
        fn_8022F500(*(u8**)(self + 0x10) + 0x44, p);
        fn_8024CB94(*(u8**)(self + 0x10), 0, 0);
    }
}