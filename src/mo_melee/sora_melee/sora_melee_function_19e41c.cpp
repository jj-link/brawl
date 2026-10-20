#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19E41C(void* p) {
    s32 v = *(s32*)((u8*)p + 8);
    return (s32)((v << 3) & 0xF0000000) >> 29;
}
