#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern OSMutex lbl_80563200;
extern int lbl_805A120C;
extern int fn_803C35A8(int *, int);
extern void fn_803C4158(int);
extern int fn_803C5FB4(int);
extern int fn_803C6084(int, int);

int fn_803C3BE8(int arg0)
{
    int index;
    int value;
    int result;

    index = -1;
    if (lbl_805A120C != 0) {
        OSLockMutex(&lbl_80563200);
    }
    value = fn_803C35A8(&index, arg0);
    if (value == 0) {
        fn_803C4158(0xB003);
        if (lbl_805A120C != 0) {
            OSUnlockMutex(&lbl_80563200);
        }
        return 0xB003;
    }
    if (index != -1) {
        result = fn_803C6084(index, value);
    } else {
        result = fn_803C5FB4(value);
    }
    fn_803C4158(result);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(&lbl_80563200);
    }
    return result;
}