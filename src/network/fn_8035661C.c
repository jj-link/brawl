#include <types.h>
#include <revolution/OS/OSMutex.h>

#pragma force_active on

extern s32 lbl_805344C8[];
extern OSMutex lbl_805344D8;
extern void (*lbl_805A1024)(s32);
extern int fn_80356508(int index, const char *str);

int fn_8035661C(const char *arg0, const char *arg1, const char *arg2)
{
    s32 *var_r29;
    s32 var_r30;

    OSLockMutex(&lbl_805344D8);

    var_r30 = 0;
    var_r29 = lbl_805344C8;
    do {
        if (*var_r29 != 0) {
            lbl_805A1024(*var_r29);
            *var_r29 = 0;
        }
        var_r30 += 1;
        var_r29 += 1;
    } while (var_r30 < 3);

    if (fn_80356508(0, arg0) != 0 && fn_80356508(1, arg1) != 0 && fn_80356508(2, arg2) != 0) {
        OSUnlockMutex(&lbl_805344D8);
        return 1;
    }

    var_r30 = 0;
    var_r29 = lbl_805344C8;
    do {
        if (*var_r29 != 0) {
            lbl_805A1024(*var_r29);
            *var_r29 = 0;
        }
        var_r30 += 1;
        var_r29 += 1;
    } while (var_r30 < 3);

    OSUnlockMutex(&lbl_805344D8);
    return 0;
}