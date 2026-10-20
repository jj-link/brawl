#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19980C(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    s32 v = (s32)(((x >> 19) & 0x1F) << 27);
    return v >> 28;
}
