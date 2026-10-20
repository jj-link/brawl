#include <types.h>
#pragma force_active on

struct fn_27_198B30_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_198B30(fn_27_198B30_obj* self)
{
    self->flags |= 0x00080000;
}
}
