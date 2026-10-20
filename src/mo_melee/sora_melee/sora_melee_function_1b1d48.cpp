#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1B1D48(void* obj) {
    u32 v = *(u32*)((char*)obj + 8);
    return (s32)((v << 12 | v >> 20) & 0xFE000000) >> 26;
}
