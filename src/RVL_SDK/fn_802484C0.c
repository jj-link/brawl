#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319E4(u32, const u8 *);
extern void fn_8024AA7C(u16);
extern void fn_8024A764(u8 *, u8, u16, u32, u32);
extern void fn_8024A8F4(u16, void *);
extern u8 lbl_804824D4[];
extern u8 lbl_8052C9B8[];

void fn_802484C0(int arg0, u8 *arg1, int arg2) {
    u8 index = (arg1 - lbl_8052C9B8) / 0x34;
    u8 *p;

    if (arg2 == 0 && arg1[0x10] == 6) {
        *(u16 *)(arg1 + 0x1A) = 0;
        arg1[0x10] = 2;
        fn_8024A764(arg1 + 1, arg1[0x12], *(u16 *)(arg1 + 0x14), 0, 0);
        fn_8024A8F4(*(u16 *)(arg1 + 0x14), lbl_8052C9B8 + 0x344);
    } else if (arg2 != 0) {
        *(u16 *)(arg1 + 0x1A) = 0xF;
        p = lbl_8052C9B8 + index * 0x34;
        if (lbl_8052C9B8[0x401] >= 4) {
            fn_802319E4(0x1E0003, lbl_804824D4);
        }
        if (*(u16 *)(p + 0x14) != 0 || *(u16 *)(p + 0x16) != 0) {
            p[0x10] = 5;
            if (*(u16 *)(p + 0x16) != 0) {
                fn_8024AA7C(*(u16 *)(p + 0x16));
            }
            if (*(u16 *)(p + 0x14) != 0) {
                fn_8024AA7C(*(u16 *)(p + 0x14));
            }
        } else {
            p[0x10] = 0;
        }
    }
}