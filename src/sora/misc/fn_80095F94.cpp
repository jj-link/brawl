#include <types.h>
#pragma force_active on

extern "C" u32 fn_80095BEC(s32, s32, s32*);

extern "C" u32 fn_80095F94(void* arg0, u32 arg1, s32* arg2, const void* arg3, float arg4) {
    s32 sp8;
    sp8 = *arg2;
    return fn_80095BEC(*(s32*)((char*)arg0 + 4), arg1, &sp8);
}
