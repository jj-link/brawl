#pragma force_active on
extern int fn_80335238(void);
extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void fn_803571F4(int, int);
extern int fn_80357D64(int);
extern int lbl_805A0FEC;
extern unsigned char lbl_805344B0[0x18];

int fn_80356108(int arg0)
{
    if (fn_80335238() != 0) {
        return 0;
    }
    OSLockMutex(lbl_805344B0);
    if (lbl_805A0FEC != 1) {
        fn_803571F4(2, 0);
        OSUnlockMutex(lbl_805344B0);
        return 0;
    }
    lbl_805A0FEC = 2;
    OSUnlockMutex(lbl_805344B0);
    if (fn_80357D64(arg0) != 0) {
        return 1;
    }
    OSLockMutex(lbl_805344B0);
    lbl_805A0FEC = 1;
    OSUnlockMutex(lbl_805344B0);
    return 0;
}
