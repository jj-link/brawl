#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern OSMutex lbl_80563200;
extern int lbl_805A120C;
extern void fn_803C7058(int);
extern int fn_803C68E0(void);
extern void fn_803C4158(int);

int fn_803C4054(int arg0)
{
    int result;

    if (lbl_805A120C != 0) {
        OSLockMutex(&lbl_80563200);
    }
    fn_803C7058(arg0);
    result = fn_803C68E0();
    fn_803C4158(result);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(&lbl_80563200);
    }
    return result;
}
