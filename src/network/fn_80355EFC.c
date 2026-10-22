#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_80355FAC(void);
extern unsigned char lbl_805344B0[0x18];
extern int lbl_805A0FEC;
extern int lbl_805A0FF0;

int fn_80355EFC(void) {
    int temp_r31;
    int var_r30 = 0;
    int temp_r4;

    OSLockMutex(lbl_805344B0);
    temp_r4 = lbl_805A0FF0;
    temp_r31 = lbl_805A0FEC;
    if (temp_r4 == 0 && temp_r31 == 4) {
        var_r30 = 1;
    } else if ((unsigned int)(*(int *)&lbl_805A0FEC - 3) <= 1U) {
        lbl_805A0FEC = 1;
    }
    if (temp_r4 == 4) {
        lbl_805A0FEC = 0;
        lbl_805A0FF0 = 0;
    }
    OSUnlockMutex(lbl_805344B0);
    if (var_r30 != 0) {
        fn_80355FAC();
        lbl_805A0FEC = 0;
        lbl_805A0FF0 = 0;
    }
    return temp_r31;
}
