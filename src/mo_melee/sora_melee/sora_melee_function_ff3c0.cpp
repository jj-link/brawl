#include <types.h>
#pragma force_active on

struct FFlagHolder {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_FF3C0(FFlagHolder* self)
{
    self->flags &= ~0x02000000;
}
