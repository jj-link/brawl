#pragma force_active on
extern unsigned int lbl_804F66E0[];
extern int lbl_804F6660[];
extern int lbl_805A0C00;
extern int lbl_805A0C04;

void fn_80213994(void) {
    int i;
    lbl_805A0C00 = 0;
    lbl_805A0C04 = 0;
    for (i = 0; i < 32; i++) {
        lbl_804F66E0[i] = 0;
        lbl_804F6660[i] = -1;
    }
}
