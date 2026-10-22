#pragma force_active on
extern int fn_80335238(void);
extern int fn_80358454(int a, int b);
extern void OSLockMutex(void *m);
extern void OSUnlockMutex(void *m);
extern unsigned char lbl_805344B0[0x18];
extern int lbl_805A0FEC;

int fn_80356424(int arg0, int arg1) {
    if (fn_80335238() != 0) {
        return 0;
    }
    OSLockMutex(lbl_805344B0);
    if (lbl_805A0FEC != 2) {
        OSUnlockMutex(lbl_805344B0);
        return 0;
    }
    OSUnlockMutex(lbl_805344B0);
    return fn_80358454(arg0, arg1);
}
