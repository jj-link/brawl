#include <types.h>
#pragma force_active on

struct PeachBitsOwner {
    u8 pad[0x1c];
    u32* bits;
};

extern "C" void fn_103_A140(PeachBitsOwner* self, u32 mask, s32 index) {
    u32* p = self->bits;
    p[index] &= ~mask;
}
