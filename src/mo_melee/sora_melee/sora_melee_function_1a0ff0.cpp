#include <types.h>
#pragma force_active on

struct fn_27_Obj {
    u32 unk0;
    u32 unk4;
    u32 mode : 3;
    u32 rest : 29;
};

extern "C" void fn_27_1A0FF0(fn_27_Obj* self, u32 mode)
{
    self->mode = mode;
}
