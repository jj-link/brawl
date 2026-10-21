#pragma force_active on
extern "C" {
extern void fn_8007CB08(void);
extern void fn_8007E88C(int);
extern int lbl_805A0214;
extern int lbl_805A022C;

void fn_8007F280(void) {
    if (lbl_805A0214 != 0) {
        fn_8007CB08();
        fn_8007E88C(lbl_805A022C);
    }
}
}
