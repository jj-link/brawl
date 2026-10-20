#include <types.h>
#pragma force_active on

struct fn_27_1A4AE0_arg {
    u8 pad[8];
    u32 field8;
};

extern "C" {
s32 fn_27_1A4AE0(fn_27_1A4AE0_arg* p) {
    u32 v = p->field8;
    return (s32)(((v >> 17) & 0xFF) << 24) >> 25;
}
}
