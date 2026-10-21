#pragma force_active on
extern void fn_801E187C(int*);
extern int lbl_805A0AB0;
extern int lbl_805A0ABC;

void fn_80200D7C(void) {
    lbl_805A0ABC = 1;
    fn_801E187C(&lbl_805A0AB0);
}