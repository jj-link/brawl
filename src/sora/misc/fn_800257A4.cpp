#pragma force_active on
extern int lbl_805A0010;
extern int lbl_805A0014;

extern "C" void fn_800257A4(int arg0, int arg1) {
    lbl_805A0010 = arg0;
    lbl_805A0014 = arg1;
}
