#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_1A6DCC(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    return ((s32)((x << 20) & 0xFFE00000)) >> 22;
}
}
