#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CFA20(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    return (s32)((v << 6) & 0xF0000000) >> 29;
}
