#include <types.h>
#pragma force_active on

extern void OSLockMutex(void*);
extern void OSUnlockMutex(void*);
extern int fn_803C5868(void*, int, int);
extern void fn_803C4158(int);
extern int lbl_805A120C;
extern unsigned char lbl_80563200[0x18];

int fn_803C3894(void* arg0, int arg1, int arg2) {
    int result;
    if (lbl_805A120C != 0) {
        OSLockMutex(lbl_80563200);
    }
    result = fn_803C5868(arg0, arg1, arg2);
    fn_803C4158(result);
    if (lbl_805A120C != 0) {
        OSUnlockMutex(lbl_80563200);
    }
    return result;
}
