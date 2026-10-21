#include <types.h>
#pragma force_active on
extern "C" s32 fn_80078D8C(s32* arg0, s32 arg1, s32 arg2) {
    s32 base = *arg0;
    s32 idx = arg2 + *(s32*)((s8*)arg0 + arg1 * 4 + 0xb8);
    return *(s32*)(base + idx * 8);
}
