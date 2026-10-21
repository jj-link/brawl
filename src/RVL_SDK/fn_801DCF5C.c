#pragma force_active on

extern int *lbl_805A06D0;

int fn_801DCF5C(int arg0, int arg1) {
    int res = lbl_805A06D0[arg0];
    lbl_805A06D0[arg0] = arg1;
    return res;
}
