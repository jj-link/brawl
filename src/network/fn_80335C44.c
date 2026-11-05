#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_80336138(int);
extern int fn_8037EFE8(void);
extern char lbl_8048936C[];
extern char lbl_80489380[];

void fn_80335C44(int *arg0) {
    fn_80335638(4, lbl_8048936C);
    *arg0 = fn_8037EFE8();
    if (arg0 == 0) {
        fn_80336138(-6);
        fn_80335638(4, lbl_80489380);
    }
}
