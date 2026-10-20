#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_14CC18(s32 p1, u32 p2, u32 p3) {
    s32 t = p1 - 0x10000;
    t += p2 * 0x6c;
    t += p3 * 4;
    return *(s32*)(t - 0x63bc);
}
