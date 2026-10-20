#include <types.h>
#pragma force_active on

extern "C" {
struct fn_27_1991D0_arg {
    u8 pad[8];
    u32 flags;
};

s32 fn_27_1991D0(fn_27_1991D0_arg* p) {
    return (s32)((p->flags << 6) & 0xF0000000) >> 29;
}
}
