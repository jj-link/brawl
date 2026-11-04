#include <types.h>
#pragma force_active on

extern "C" s32 fn_801AF98C(void* arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        return *(s32*)((u8*)arg0 + 0x124);
    case 1:
        return *(s32*)((u8*)arg0 + 0x128);
    case 2:
        return *(s32*)((u8*)arg0 + 0x12C);
    case 3:
        return *(s32*)((u8*)arg0 + 0x130);
    case 4:
        return *(s32*)((u8*)arg0 + 0x134);
    case 5:
    case 6:
    default:
        return 0;
    }
}
