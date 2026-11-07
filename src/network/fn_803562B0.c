#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern int fn_80335238(void);
extern void fn_803571F4(int, int);
extern int fn_803581CC(int, int, int);
extern OSMutex lbl_805344B0;
extern int lbl_805A0FEC;

int fn_803562B0(int arg0, int arg1, int arg2)
{
    if (fn_80335238() != 0) {
        return 0;
    }
    OSLockMutex(&lbl_805344B0);
    if (lbl_805A0FEC != 1) {
        fn_803571F4(2, 0);
        OSUnlockMutex(&lbl_805344B0);
        return 0;
    }
    lbl_805A0FEC = 2;
    OSUnlockMutex(&lbl_805344B0);
    if (fn_803581CC(arg0, arg1, arg2) != 0) {
        return 1;
    }
    OSLockMutex(&lbl_805344B0);
    lbl_805A0FEC = 1;
    OSUnlockMutex(&lbl_805344B0);
    return 0;
}