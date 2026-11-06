#include <types.h>
#include <revolution/OS/OSMutex.h>

#pragma force_active on

extern s32 fn_8039602C(void *);
extern OSMutex lbl_805344D8;
extern OSMutex lbl_80534580;
extern s32 lbl_805A0FF8;
extern s32 lbl_805A0FFC;
extern void *lbl_805A1004;

s32 fn_80357378(void)
{
    s32 temp_r30;

    if (lbl_805A0FF8 == 0) {
        return 0;
    }
    OSLockMutex(&lbl_80534580);
    temp_r30 = lbl_805A0FFC == 0;
    if (temp_r30 != 0) {
        lbl_805A0FFC = 1;
    }
    OSUnlockMutex(&lbl_80534580);
    if (temp_r30 == 0) {
        OSLockMutex(&lbl_805344D8);
        temp_r30 = (s32) lbl_805A1004;
        OSUnlockMutex(&lbl_805344D8);
        return fn_8039602C((void *) temp_r30) == 0;
    }
    OSLockMutex(&lbl_80534580);
    lbl_805A0FFC = 0;
    OSUnlockMutex(&lbl_80534580);
    return 0;
}
