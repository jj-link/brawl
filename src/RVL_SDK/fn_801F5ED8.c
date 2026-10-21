#pragma force_active on
extern int lbl_805A08E0;
extern char *lbl_805A08E4;
extern int *lbl_805A08E8;
extern unsigned int lbl_805A08EC;

void fn_801F5ED8(void) {
    int n;
    int *p;

    lbl_805A08EC = 0x80000000;
    p = *(int **)(0x80000000 + 0x38);
    lbl_805A08E8 = p;
    if (p == 0) {
        return;
    }
    n = p[2];
    lbl_805A08E0 = n;
    lbl_805A08E4 = (char *)p + n * 12;
}
