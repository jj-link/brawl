#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern int lbl_805A1174;

int fn_8039A29C(int arg0) {
    int var_r31;
    int temp_r4;
    int level;

    var_r31 = 0;
    level = OSDisableInterrupts();
    if (arg0 != 0) {
        if (lbl_805A1174 == 0) {
            lbl_805A1174 = 3;
        } else if (lbl_805A1174 == 1) {
            var_r31 = -10;
        } else {
            var_r31 = -26;
        }
    } else {
        temp_r4 = (lbl_805A1174 - 3) == 0;
        if (temp_r4 != 0) {
            lbl_805A1174 = 0;
        }
        if (temp_r4 == 0) {
            var_r31 = -9;
        }
    }
    OSRestoreInterrupts(level);
    return var_r31;
}
