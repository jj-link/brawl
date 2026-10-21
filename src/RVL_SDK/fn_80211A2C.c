#pragma force_active on
extern unsigned char lbl_805A0BD8;
extern int lbl_805A0BDC;
extern int lbl_805A0BE0;
extern int lbl_805A0BE4;
extern int lbl_805A0BE8;
int fn_801E2420(void);
int fn_801E2428(void);

void fn_80211A2C(void) {
    if (lbl_805A0BD8 == 0) {
        int ret;
        lbl_805A0BE8 = fn_801E2420();
        ret = fn_801E2428();
        lbl_805A0BE4 = ret;
        lbl_805A0BE0 = lbl_805A0BE8;
        lbl_805A0BDC = ret;
        lbl_805A0BD8 = 1;
    }
}
