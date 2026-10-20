#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1D01A4(void* p) {
    return (s32)((*(u32*)((u8*)p + 8) << 4) & 0xF8000000) >> 28;
}
