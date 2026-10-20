#include <types.h>
#pragma force_active on

struct C990C {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_C990C(C990C* self)
{
    self->flags |= 0x00400000;
}
