#pragma force_active on

extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_803C4158(int);
extern int fn_803C6C10(int, int);
extern int fn_803C7058(int);
extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];

int fn_803C40C4(int arg0, int arg1) {
    int temp;

    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    if (arg0 != 0) {
        temp = fn_803C7058(arg0);
        arg1 = fn_803C6C10(temp, arg1);
    } else {
        arg1 = -1;
    }
    fn_803C4158(arg1);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
    return arg1;
}
