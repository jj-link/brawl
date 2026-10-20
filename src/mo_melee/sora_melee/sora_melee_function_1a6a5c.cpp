#include <types.h>
#pragma force_active on

struct fn_27_1A6A5C_arg {
    u8 pad[8];
    u32 flags;
};

extern "C" s32 fn_27_1A6A5C(fn_27_1A6A5C_arg* p) {
    u32 x = p->flags;
    return ((s32)((x & 0x003FF800) << 10)) >> 22;
}
