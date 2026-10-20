#include <types.h>
#pragma force_active on

struct fn_27_B042C_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
int fn_27_B042C(fn_27_B042C_arg* p)
{
    u32 x = p->unk8;
    return ((s32)(((x << 5) | (x >> 27)) & 0xFC000000)) >> 27;
}
}
