#include <types.h>
#pragma force_active on

struct fn_27_CB388_t
{
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_CB388(fn_27_CB388_t* self)
{
    self->flags |= 0x80;
}
