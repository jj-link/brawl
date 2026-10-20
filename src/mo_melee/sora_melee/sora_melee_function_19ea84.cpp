#include <types.h>
#pragma force_active on

struct fn_27_19EA84_arg {
    u32 pad[2];
    u32 field8;
};

extern "C" {
s32 fn_27_19EA84(fn_27_19EA84_arg* p)
{
    return (s32)((p->field8 << 12) & 0xFE000000) >> 26;
}
}
