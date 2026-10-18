#include <types.h>
#pragma force_active on

struct PeachThing
{
    u32 unk0;
    u32 unk4;
    u32 f0    : 18;
    u32 field : 1;
    u32 f1    : 13;
};

extern "C" s32 fn_103_F750(const PeachThing *p)
{
    return p->field;
}
