#include <types.h>
#pragma force_active on

extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" s32 fn_80046554(void* arg0, s32 archiveId, s32 nodeType, s32 arg3, s32* arg4, s32 arg5, s32 arg6);

extern "C" s32 fn_27_2B2764(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp8;
    s32 var_r31;

    if (arg1 == 0) {
        var_r31 = *(s32*)((u8*)arg0 + 0x14);
    } else if (arg1 == 1) {
        var_r31 = *(s32*)((u8*)arg0 + 0x18);
    } else {
        return 0;
    }
    sp8 = 0;
    void* mgr = getManager__11soArchiveDbFUl(2);
    return fn_80046554(mgr, var_r31, arg2, arg3, &sp8, arg4, -1);
}
