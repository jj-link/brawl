#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, u16, int, u8);
extern u8 lbl_8052CDC0[];
extern char lbl_80483DCC[];
void fn_8024EAE8(u8 *self, int a, u32 b)
{
    u8 *p;
    p = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), 8, 3, self[0x36]);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) fn_802319E4(0x80001, lbl_80483DCC);
    } else {
        p[0x14] = (u8)*(u16 *)(self + 0x14);
        p[0x15] = (u8)((int)*(u16 *)(self + 0x14) >> 8);
        p[0x16] = (u8)*(u16 *)(self + 0x16);
        p[0x17] = (u8)((int)*(u16 *)(self + 0x16) >> 8);
        p[0x18] = (u8)a;
        p[0x19] = (u8)(a >> 8);
        p[0x1A] = (u8)b;
        p[0x1B] = (u8)(b >> 8);
        fn_8024CB94((void *)*(u32 *)(self + 0x10), 0, p);
    }
}