#include <types.h>
#pragma force_active on

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
};

extern "C" {
void* fn_27_1AFC4C(fn27Obj* p, s32 idx)
{
    s32 i = (p->unk8 >> 22) + idx;
    if (i >= 0x13a) {
        i -= 0x13a;
    }
    return (char*)p + i * 4 + 0xc;
}
}
