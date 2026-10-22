#pragma force_active on
extern void fn_801FEC04(void *dst, unsigned int size);
extern void fn_80200A18(void);
extern void fn_802099DC(void *p);
extern unsigned char lbl_804E84C0[];
extern unsigned char lbl_804E8940[];
extern unsigned int lbl_805A0AA8;
extern unsigned int lbl_805A0AC8;
extern unsigned int lbl_805A0ACC;
extern unsigned int lbl_805A0AD0;

void fn_80200C78(void) {
    unsigned int temp_r4;

    if (lbl_805A0AC8 == 1) {
        lbl_805A0AC8 = 0;
        fn_80200A18();
    } else {
        lbl_805A0AC8 = 2;
        fn_802099DC(lbl_804E8940);
    }
    if (lbl_805A0AA8 == 1) {
        fn_801FEC04(lbl_804E84C0 + lbl_805A0ACC * 0x180, 0x180);
        temp_r4 = lbl_805A0ACC + 1;
        temp_r4 = temp_r4 % 3;
        if (temp_r4 != lbl_805A0AD0) {
            lbl_805A0ACC = temp_r4;
        }
    }
}
