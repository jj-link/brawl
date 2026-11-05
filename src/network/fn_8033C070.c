#pragma force_active on
extern void fn_80374C10(void);
extern int fn_8035C658(void);
extern void fn_80335638(int level, const char *fmt, ...);
extern void fn_8033524C(int arg0, int arg1);
extern char lbl_8048AA40[];
extern int lbl_805A0F8C;
extern int *lbl_805A0F88;

void fn_8033C070(void) {
    fn_80374C10();
    lbl_805A0F8C = fn_8035C658();
    fn_80335638(2, lbl_8048AA40, lbl_805A0F8C);
    fn_8033524C(9, 0xFFFE8515);
    *lbl_805A0F88 = 0;
}
