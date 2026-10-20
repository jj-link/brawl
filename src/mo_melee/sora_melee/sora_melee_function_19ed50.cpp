#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_19ED50(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    return ((s32)(((v >> 21) & 0x3F) << 26)) >> 27;
}
}
