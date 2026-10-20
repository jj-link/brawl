#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A026C(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    s32 r = (s32)((v << 6) & 0xF0000000);
    return r >> 29;
}
