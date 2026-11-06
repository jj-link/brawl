#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_802471C8(char *p);
extern void fn_80231FB0(char *p, int a, int b);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void fn_802474F8(void);
extern char lbl_8052C870[];

void fn_802473A0(int arg0, u8 arg1, int arg2) {
    u8 sp8;
    u16 spA;
    void (*cb)(int, int, void *);

    sp8 = arg0;
    spA = arg2;
    if (*(u8 *)(lbl_8052C870 + 0x140) != 0) {
        *(u8 *)(lbl_8052C870 + 0x6E) = 0;
        if ((u8)arg0 != 0) {
            cb = *(void (**)(int, int, void *))(lbl_8052C870 + 0xC4);
            if (cb != 0) {
                cb(4, *(u8 *)(lbl_8052C870 + 0x6F), &sp8);
            }
        } else {
            u16 a2 = arg2;
            *(u8 *)(lbl_8052C870 + 0x6A) = arg1;
            *(u16 *)(lbl_8052C870 + 0x6C) = arg2;
            if (*(u8 *)(lbl_8052C870 + 0x78) != 0xFF) {
                if (*(u8 *)(lbl_8052C870 + 0x78) != arg1 || (*(u8 *)(lbl_8052C870 + 0x78) != 0 && (a2 < *(u16 *)(lbl_8052C870 + 0x72) || a2 > *(u16 *)(lbl_8052C870 + 0x70)))) {
                    fn_802471C8(lbl_8052C870 + 0x70);
                } else {
                    *(u8 *)(lbl_8052C870 + 0x78) = 0xFF;
                }
            } else if (arg1 == 0) {
                memcpy(lbl_8052C870 + 0x70, lbl_8052C870 + 0x4C, 0xA);
                fn_802471C8(lbl_8052C870 + 0x4C);
                *(u8 *)(lbl_8052C870 + 0x6F) = 0;
                *(void (**)(void))(lbl_8052C870 + 0x44) = fn_802474F8;
                fn_80231FB0(lbl_8052C870 + 0x34, 0x16, 0x3C);
            }
            cb = *(void (**)(int, int, void *))(lbl_8052C870 + 0xC4);
            if (cb != 0) {
                cb(3, arg1, &spA);
            }
        }
    }
}
