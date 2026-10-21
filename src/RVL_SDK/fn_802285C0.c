#pragma force_active on
extern int fn_801D536C(void);
extern int lbl_805A0CCC;

int fn_802285C0(void) {
    if (!(fn_801D536C() & 0x10000000)) {
        lbl_805A0CCC = 0;
        return 2;
    }
    lbl_805A0CCC = 0xA5FF005A;
    return 0;
}
