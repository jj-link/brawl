#include <types.h>
#pragma force_active on

extern "C" s32 fn_121_B688();

extern "C" s32 fn_121_B694(char* self, void* unused, s32 a, s32 b) {
    s32* table = *(s32**)(self - 0x10000 + fn_121_B688() * 0x18 + a * 4 - 0x7648);
    return table[b];
}
