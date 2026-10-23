#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, u16, int, u32);
extern u8 lbl_8052CDC0[];
extern char lbl_80483DCC[];

void fn_8024F8C4(u8 *self, u32 a, u32 b)
{
    u8 *p;

    p = fn_8024E864(*(u16 *)(self + 0x28), 4, 0xB, a);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483DCC);
        }
    } else {
        p[0x14] = (u8)b;
        p[0x15] = (u8)(b >> 8);
        p[0x16] = 1;
        p[0x17] = 0;
        fn_8024CB94(self, 0, p);
    }
}
