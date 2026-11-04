#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern int lbl_805A120C;
extern OSMutex lbl_80563200;
extern int fn_803C7058(int);
extern int fn_803C51F8(unsigned, unsigned);
extern void fn_803C4158(int);
extern int fn_803C49B8(unsigned);
extern void fn_803C72A0(int);

int fn_803C34CC(int arg0)
{
    int result;

    if (lbl_805A120C != 0) {
        OSLockMutex(&lbl_80563200);
    }
    result = fn_803C51F8(fn_803C7058(arg0), 0);
    fn_803C4158(result);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(&lbl_80563200);
    }
    if (result == 0) {
        if (lbl_805A120C != 0) {
            OSLockMutex(&lbl_80563200);
        }
        result = fn_803C49B8(fn_803C7058(arg0));
        if (result == 0) {
            fn_803C72A0(arg0);
        }
        fn_803C4158(result);
        if (lbl_805A120C != 0) {
            OSUnlockMutex(&lbl_80563200);
        }
    }
    return result;
}