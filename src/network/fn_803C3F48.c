#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_803C4158(int);
extern int fn_803C67E4(void);
extern int fn_803C6890(void);
extern void fn_803C7058(int);
extern unsigned char lbl_80563200[0x18];
extern int lbl_805A120C;

int fn_803C3F48(int arg0) {
    int var_r31;

    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    if (arg0 != 0) {
        fn_803C7058(arg0);
        var_r31 = fn_803C6890();
    } else {
        var_r31 = fn_803C67E4();
    }
    fn_803C4158(var_r31);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
    return var_r31;
}
