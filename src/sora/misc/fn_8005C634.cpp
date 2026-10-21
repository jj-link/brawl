#pragma force_active on
extern "C" {

extern int lbl_805A0118[2];
extern int lbl_805A0120[2];

void fn_8005C634(int a0, int a1, int a2, int a3) {
    lbl_805A0118[0] = a0;
    lbl_805A0118[1] = a1;
    lbl_805A0120[0] = a2;
    lbl_805A0120[1] = a3;
}

}
