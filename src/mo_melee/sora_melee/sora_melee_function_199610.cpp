#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_199610(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    return (s32)(((x >> 25) & 0xF) << 28) >> 29;
}
