#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_4CB34(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    return (s32)(((x >> 27) & 7) << 29) >> 30;
}
