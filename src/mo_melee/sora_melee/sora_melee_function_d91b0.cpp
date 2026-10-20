#include <types.h>
#pragma force_active on

struct Fn27Wrap {
    u8 pad[8];
    s32 val;
};

extern "C" {
void* fn_27_D91B0(Fn27Wrap* p, s32 idx)
{
    s32 i = (p->val >> 24) + idx;
    if (i >= 0x4c) {
        i -= 0x4c;
    }
    return (char*)p + i * 0x30 + 0xc;
}
}
