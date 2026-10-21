#pragma force_active on
extern "C" {
extern void fn_801D7928(void);
extern int *lbl_805A01F8;

void fn_8007BD5C(void) {
    fn_801D7928();
    if (lbl_805A01F8) {
        *lbl_805A01F8 = 0;
    }
}
}
