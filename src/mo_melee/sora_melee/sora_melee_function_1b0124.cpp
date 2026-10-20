#include <types.h>
#pragma force_active on

extern "C" {
struct fn27Obj {
    u8 pad[8];
    s32 unk8;
};
}

extern "C" void* fn_27_1B0124(fn27Obj* p, s32 idx)
{
    s32 i = (p->unk8 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (char*)p + i * 0x30 + 0xc;
}
