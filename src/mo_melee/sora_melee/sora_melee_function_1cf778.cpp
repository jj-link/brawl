#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1CF778(void* self) {
    s32 val = *(s32*)((u8*)self + 8);
    return val >> 27;
}
