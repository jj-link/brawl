#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, u16, int, u32);
extern void fn_8022F500(void *, void *);
extern u8 lbl_8052CDC0[];
extern char lbl_80483DCC[];

void fn_8024F4F8(u8 *self, u32 a, int b, u32 c)
{
    u8 *p = fn_8024E864(*(u16 *)(self + 0x28), 4, 7, a);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483DCC);
        }
    } else {
        p[0x14] = b;
        p[0x15] = b >> 8;
        p[0x16] = c;
        p[0x17] = c >> 8;
        *(u16 *)(p + 6) = 0;
        fn_8022F500(self + 0x44, p);
        fn_8024CB94(self, 0, 0);
    }
}