#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern OSMutex lbl_80563200;
extern int lbl_805A120C;
extern int fn_803C661C(int);
extern void fn_803C4158(int);

int fn_803C3ED8(int arg0)
{
    int result;

    if (lbl_805A120C != 0) {
        OSLockMutex(&lbl_80563200);
    }
    result = fn_803C661C(arg0);
    fn_803C4158(result);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(&lbl_80563200);
    }
    return result;
}