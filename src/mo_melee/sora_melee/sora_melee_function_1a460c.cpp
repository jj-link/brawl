#include <types.h>
#pragma force_active on

struct FnObj27 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A460C(FnObj27* obj)
{
    obj->flags &= ~0x2u;
}
