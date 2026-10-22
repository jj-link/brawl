#include <types.h>
#pragma force_active on

extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern s32 fn_803DBBC8(void *);
extern s32 fn_803E9974(void *);
extern char lbl_805644C0[];

s32 fn_803DC120(u8 *arg0) {
    u8 *temp_r30;
    s32 result;

    temp_r30 = *(u8 **)(arg0 + 8);
    PF_enterCritical(temp_r30 + 0x1F90);
    result = fn_803E9974(temp_r30);
    if (result != 0) {
        PF_exitCritical(temp_r30 + 0x1F90);
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(temp_r30 + 0x1F80) = result;
        return result;
    }
    result = fn_803DBBC8(arg0);
    if (result != 0) {
        *(s32 *)(lbl_805644C0 + 0x40) = result;
        *(s32 *)(temp_r30 + 0x1F80) = result;
    }
    PF_exitCritical(temp_r30 + 0x1F90);
    return result;
}
