#pragma force_active on
extern char lbl_804E7AE0[];
extern char *lbl_805A0A8C;
extern int lbl_805A0A90;
char *fn_801FFF98(void) {
    char *ret = lbl_804E7AE0 + (lbl_805A0A90 << 7);
    lbl_805A0A90 = (lbl_805A0A90 + 1) & 1;
    lbl_805A0A8C = lbl_804E7AE0 + (lbl_805A0A90 << 7);
    return ret;
}