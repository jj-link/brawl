#include <types.h>
#pragma force_active on

struct FooObj {
    u32 unk0;
    u32 unk4;
    u32 pad0 : 3;
    u32 flags : 3;
    u32 rest : 26;
};

extern "C" void fn_27_199008(FooObj* self, u32 val)
{
    self->flags = val;
}
