#pragma force_active on
typedef unsigned char u8;
extern char lbl_80529CF8[];
extern char lbl_80481560[];
extern void fn_80231A2C(int, char *, int, int, int);
extern void fn_80245F58(int);
extern void *memcpy(void *, const void *, unsigned long);

void fn_8023F4A8(u8 a, void *b, u8 c)
{
    if ((u8)lbl_80529CF8[0x27C0] >= 3U) {
        fn_80231A2C(0xD0002, lbl_80481560, a, (int)b, c);
    }
    if ((u8)lbl_80529CF8[0x64E] > 1U) {
        fn_80245F58(a);
    }
    lbl_80529CF8[0x20] = a;
    lbl_80529CF8[0x21] = c;
    memcpy(lbl_80529CF8 + 0x22, b, c);
}
