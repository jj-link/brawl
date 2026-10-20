#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u8 pad_0[8];
    u32 unk8;
};

extern "C" s32 fn_27_1987D0(Fn27Obj* p)
{
    return (s32)((p->unk8 << 2) & 0xE0000000) >> 30;
}
