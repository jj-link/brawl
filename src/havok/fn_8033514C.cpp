#pragma force_active on
extern int lbl_805A0F48;
extern int lbl_805A0F4C;

extern "C" {
int fn_8033514C(int *arg0) {
    if (arg0 != 0) {
        *arg0 = lbl_805A0F4C;
    }
    return lbl_805A0F48;
}
}
