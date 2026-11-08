#include <types.h>
#pragma force_active on

extern "C" void* memcpy(void* dst, const void* src, u32 n);
extern u32 lbl_8059C800;

extern "C" s32 fn_8004B278(u8* arg0, u32* arg1, u32 arg2) {
    s32 var_r7;
    if (arg1 == NULL || arg2 == 0) {
        return 0;
    }
    var_r7 = 0;
    if (*(u32*)(arg0 + 0x34) >= arg2 && *arg1 == lbl_8059C800) {
        *(u32*)(arg0 + 0x0) = 0;
        memcpy(*(void**)(arg0 + 0x24), arg1, arg2);
        var_r7 = 1;
    }
    return var_r7;
}
