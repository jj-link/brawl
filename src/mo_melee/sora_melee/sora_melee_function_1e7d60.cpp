#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_1E7D60(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    return (s32)((v << 2) & 0xE0000000) >> 30;
}
}
