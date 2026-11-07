#include <revolution/OS/OSMutex.h>
#include <string.h>
#pragma force_active on

extern int fn_80335238(void);
extern void fn_803571F4(int, int);
extern int fn_80357E38(void *, void *, int);
extern OSMutex lbl_805344B0;
extern int lbl_805A0FEC;

int fn_803561C4(void *arg0, void *arg1, int arg2)
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
    memset(arg0, 0, arg2 * 0xb0);
    if (fn_80357E38(arg0, arg1, arg2) != 0) {
        return 1;
    }
    OSLockMutex(&lbl_805344B0);
    lbl_805A0FEC = 1;
    OSUnlockMutex(&lbl_805344B0);
    return 0;
}