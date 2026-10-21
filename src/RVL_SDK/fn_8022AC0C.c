#pragma force_active on
extern char lbl_804FC200[];
extern void fn_8022AAB0(void);
extern void fn_801D81C4(int, int, int, int, void (*)(void), void *);

void fn_8022AC0C(int a, int b) {
    fn_801D81C4(a, b, 0, 0, fn_8022AAB0, lbl_804FC200 + 0x1000);
}
