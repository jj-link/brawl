extern int lbl_8059E9F8;
extern int lbl_805A0700;

#pragma force_active on
void fn_801E2430(void) {
    int *p = (int *)0x80000000;
    lbl_8059E9F8 = p[0x3130 / 4];
    lbl_805A0700 = p[0x3134 / 4];
}
