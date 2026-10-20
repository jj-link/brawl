#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_D04E4(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    return ((s32)((v << 7) & 0xFF000000)) >> 25;
}
