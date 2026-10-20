#include <types.h>
#pragma force_active on

struct fn_27_1C5DCC_Self {
    u8 pad[0x18];
    s32 val;
};

extern "C" u8* fn_27_1C5DCC(fn_27_1C5DCC_Self* self, s32 idx)
{
    s32 i = (self->val >> 25) + idx;
    if (i >= 0x28) {
        i -= 0x28;
    }
    return (u8*)self + i * 0xC + 0x1C;
}
