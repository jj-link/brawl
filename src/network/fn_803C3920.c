#pragma force_active on
extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_803C4158(void);
extern int fn_803C5970(int, int, int, int);

int fn_803C3920(int arg0, int arg1, int arg2, int arg3) {
    int temp_r31;

    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    temp_r31 = fn_803C5970(arg3, arg1, arg2, arg0);
    fn_803C4158();
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
    return temp_r31;
}
