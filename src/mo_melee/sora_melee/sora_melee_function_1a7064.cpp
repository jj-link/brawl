#include <types.h>
#pragma force_active on

struct Fn1A7064Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1A7064(Fn1A7064Obj* p)
{
    u32 x = p->unk8;
    x = (x >> 28) | (x << 4);
    return ((s32)(x & 0xF8000000)) >> 28;
}
