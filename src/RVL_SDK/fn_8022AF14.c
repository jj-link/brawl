#pragma force_active on
extern void fn_801D81C4(int, int, int, int, void (*)(void), void *);
extern void fn_8022AD40(void);
extern char lbl_804FC200[];

void fn_8022AF14(int a, int b) {
    fn_801D81C4(a, b, 0, 0, fn_8022AD40, lbl_804FC200 + 0x1000);
}
