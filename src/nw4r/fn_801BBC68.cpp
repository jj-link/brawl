#pragma force_active on
extern "C" {
void fn_80203CEC(int, int);
extern int lbl_805A0570;

void fn_801BBC68(int unused, int arg2, int arg3) {
    fn_80203CEC(arg2, arg3);
    lbl_805A0570 = 0;
}
}
