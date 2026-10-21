#include <types.h>
#pragma force_active on

int fn_801E2420(void);
int fn_801E2428(void);
extern s8 lbl_805A0BD8;
extern int lbl_805A0BDC;
extern int lbl_805A0BE0;
extern int lbl_805A0BE4;
extern int lbl_805A0BE8;

void fn_80211A78(void) {
    int temp_r3;

    lbl_805A0BD8 = 0;
    lbl_805A0BE8 = fn_801E2420();
    temp_r3 = fn_801E2428();
    lbl_805A0BE4 = temp_r3;
    lbl_805A0BE0 = lbl_805A0BE8;
    lbl_805A0BDC = temp_r3;
    lbl_805A0BD8 = 1;
}
