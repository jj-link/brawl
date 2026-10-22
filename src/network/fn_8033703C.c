#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern int fn_80367F78(int, int, int, int, void *, int);
extern const char lbl_80489508[];
extern const char lbl_80489524[];
extern void fn_80338358(void);

int fn_8033703C(int arg0, int *arg1) {
    fn_80335638(0x20000, lbl_80489524, *arg1);
    fn_80335638(0x20000, lbl_80489508);
    fn_80367F78(arg0, *arg1, 0, 0, fn_80338358, 0);
    return 1;
}
