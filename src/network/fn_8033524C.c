#pragma force_active on
extern int lbl_805A0F48;
extern int lbl_805A0F4C;

void fn_8033524C(int arg0, int arg1) {
    if (lbl_805A0F48 == 9)
        return;
    lbl_805A0F48 = arg0;
    lbl_805A0F4C = arg1;
}
