#pragma force_active on
extern int lbl_805A0630;

int fn_801D6620(void) {
    if (lbl_805A0630 != 0) {
        return 0x40;
    }
    return *(unsigned char *)0x80003184;
}
