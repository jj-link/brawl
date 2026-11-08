#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, int, void *);
extern u8 *fn_8024E864(u16, int, int, u32);
extern u8 lbl_8052CDC0[];
extern char lbl_80483E0C[];
void fn_8024F5B8(u8 *self, u8 *src, int len)
{
    u8 *p;
    u8 *dst;
    int i;
    p = fn_8024E864(*(u16 *)(self + 0x28), len, 8, ++self[0x31]);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483E0C);
        }
    } else {
        dst = p + 0x14;
        if (len != 0) {
            for (i = 0; i < len; i++) {
                u8 *s = src + i;
                *dst++ = *s;
            }
        }
        fn_8024CB94(self, 0, p);
    }
}