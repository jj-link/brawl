#pragma force_active on
extern char lbl_804E5B60[];
extern int lbl_805A0A38;
extern int lbl_805A0A64;

void fn_801FF95C(void **arg0) {
    if (lbl_805A0A64 != 0) {
        *arg0 = lbl_804E5B60 + lbl_805A0A38 * 0x600;
    } else {
        *arg0 = 0;
    }
}
