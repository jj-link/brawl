#pragma force_active on
extern int lbl_8059ECB8;
extern char lbl_8059ECC0;
int fn_802123A8(void *p, int flag);

int fn_80211080(void) {
    int temp_r3;
    int var_r31;

    var_r31 = 0;
    if (lbl_8059ECB8 < 0) {
        temp_r3 = fn_802123A8(&lbl_8059ECC0, 0);
        lbl_8059ECB8 = temp_r3;
        if (temp_r3 < 0) {
            var_r31 = temp_r3;
        }
    }
    return var_r31;
}
