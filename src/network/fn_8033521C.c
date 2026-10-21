#pragma force_active on
extern int lbl_805A0F48;
extern int lbl_805A0F4C;

void DWC_ClearError(void) {
    if (lbl_805A0F48 != 9) {
        lbl_805A0F48 = 0;
        lbl_805A0F4C = 0;
    }
}
