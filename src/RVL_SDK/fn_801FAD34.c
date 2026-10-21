#pragma force_active on
extern int lbl_8059EADC;

int fn_801FAD34(int value) {
    int old = lbl_8059EADC;
    lbl_8059EADC = value;
    return old;
}
