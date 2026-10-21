#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_8037EA50(void);
extern char lbl_80489310[];
extern int lbl_805A0F6C;

int fn_80335988(void) {
    fn_80335638(4, lbl_80489310);
    fn_8037EA50();
    lbl_805A0F6C = lbl_805A0F6C + 1;
    return 1;
}
