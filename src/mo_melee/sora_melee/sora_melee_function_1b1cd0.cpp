#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1B1CD0(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    return (s32)((x << 12) & 0xFE000000) >> 26;
}
