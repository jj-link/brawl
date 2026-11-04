#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern OSMutex lbl_80563200;
extern int lbl_805A120C;
extern int fn_803C35A8(int *, int);
extern void fn_803C4158(int);
extern int fn_803C5BF4(int);
extern int fn_803C5CC4(int, int);

int fn_803C3A48(int arg0)
{
    int index = -1;
    int value;
    int result;
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
        result = fn_803C5CC4(index, value);
    } else {
        result = fn_803C5BF4(value);
    }
    fn_803C4158(result);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(&lbl_80563200);
    }
    return result;
}