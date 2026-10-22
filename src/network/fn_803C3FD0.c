#pragma force_active on
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_803C4158(int);
extern int fn_803C66F4(void);
extern void fn_803C7058(int);
extern unsigned char lbl_80563200[0x18];
extern int lbl_805A120C;

int fn_803C3FD0(int arg0)
{
    int result;

    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    if (arg0 != 0) {
        fn_803C7058(arg0);
        result = fn_803C66F4();
    } else {
        fn_803C4158(-1);
        result = -1;
    }
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
    return result;
}
