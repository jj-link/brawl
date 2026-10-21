#pragma force_active on
extern unsigned int lbl_805A0AC8;
extern void (*lbl_805A0A98)(void);
extern void fn_80200A18(void);

void fn_80200D28(void) {
    if (lbl_805A0AC8 == 2) {
        lbl_805A0AC8 = 0;
        fn_80200A18();
        if (lbl_805A0A98 != 0) {
            lbl_805A0A98();
        }
    } else {
        lbl_805A0AC8 = 1;
    }
}
