#pragma force_active on
extern void fn_801D81C4(int, int, int, int, void *, void *);
extern void fn_80218134(void);
extern char lbl_804F6820[];

void fn_8021885C(int a, int b) {
    fn_801D81C4(a, b, 0, 0, (void *)fn_80218134, (void *)(lbl_804F6820 + 0x1000));
}
