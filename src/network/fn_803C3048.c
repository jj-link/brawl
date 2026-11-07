#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern int lbl_805A120C;
extern OSMutex lbl_80563200;
extern int fn_803C4E74(char *, int);

int fn_803C3048(char *arg0, int arg1)
{
    int result;
    if (lbl_805A120C != 0) {
        OSLockMutex(&lbl_80563200);
    }
    result = fn_803C4E74(arg0, arg1);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(&lbl_80563200);
    }
    return result;
}