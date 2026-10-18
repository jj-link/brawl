#include <types.h>
#pragma force_active on

struct FtPeachTable {
    u8 pad0[0x18];
    s32 count;
    u8 pad1[0x8];
    s32 data[1];
};

extern "C" s32 fn_103_134CC(FtPeachTable* self, s32 unused, s32 index)
{
    return self->data[index - self->count];
}
