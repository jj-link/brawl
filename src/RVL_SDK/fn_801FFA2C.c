#pragma force_active on
extern char lbl_804E6D60[];
extern int lbl_805A0A38;
extern int lbl_805A0A60;

void fn_801FFA2C(void **arg0) {
    if (lbl_805A0A60 != 0) {
        *arg0 = lbl_804E6D60 + lbl_805A0A38 * 0x480;
        return;
    }
    *arg0 = 0;
}
