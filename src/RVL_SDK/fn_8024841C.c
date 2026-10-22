#pragma force_active on
extern void fn_802319E4(unsigned int, const void *);
extern void fn_8024AA7C(unsigned short);
extern unsigned char lbl_804824D4[];
extern unsigned char lbl_8052C9B8[];

int fn_8024841C(int arg0) {
    unsigned char *r31;

    r31 = lbl_8052C9B8 + arg0 * 0x34;
    if (lbl_8052C9B8[0x401] >= 4) {
        fn_802319E4(0x1E0003, lbl_804824D4);
    }
    if (*(unsigned short *)(r31 + 0x14) != 0 || *(unsigned short *)(r31 + 0x16) != 0) {
        r31[0x10] = 5;
        if (*(unsigned short *)(r31 + 0x16) != 0) {
            fn_8024AA7C(*(unsigned short *)(r31 + 0x16));
        }
        if (*(unsigned short *)(r31 + 0x14) != 0) {
            fn_8024AA7C(*(unsigned short *)(r31 + 0x14));
        }
    } else {
        r31[0x10] = 0;
    }
    return 0;
}
