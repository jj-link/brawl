#pragma force_active on
extern void fn_801D81C4(void *a, void *b, int c, int d,
                       void (*e)(void), void *f);
extern void fn_8022A058(void);
extern char lbl_804FC200[];

void fn_8022A944(void *a, void *b) {
    fn_801D81C4(a, b, 0, 0, fn_8022A058, lbl_804FC200 + 0x1000);
}
