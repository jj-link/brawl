#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2961DC(void* self) {
    return (s32)((*(u32*)((u8*)self + 8) << 12) & 0xFE000000) >> 26;
}
