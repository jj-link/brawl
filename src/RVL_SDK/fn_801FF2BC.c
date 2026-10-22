#pragma force_active on
extern unsigned int lbl_804E4850[];
extern unsigned int lbl_804E48D0[];
extern int lbl_805A0A28;

void fn_801FF2BC(void) {
    int i;
    lbl_805A0A28 = 0;
    for (i = 0; i < 32; i++) {
        lbl_804E48D0[i] = 0;
        lbl_804E4850[i] = 0;
    }
}
