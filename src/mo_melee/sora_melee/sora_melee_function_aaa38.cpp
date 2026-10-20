#include <types.h>
#pragma force_active on

struct fn27_AAA38_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_AAA38(fn27_AAA38_obj* p)
{
    return ((s32)((p->unk8 << 5) & 0xFC000000)) >> 27;
}
}
