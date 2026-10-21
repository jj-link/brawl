#pragma force_active on
extern int lbl_805A1310;

int gdev_cc_open(void) {
    if (lbl_805A1310 != 0) {
        return -0x2715;
    }
    lbl_805A1310 = 1;
    return 0;
}
