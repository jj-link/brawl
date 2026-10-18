#include <types.h>
#pragma force_active on

struct LucasIndexed {
    u8 pad[0x18];
    s32 base;
};

extern "C" u32 fn_114_1E594(LucasIndexed* self, s32 unused, s32 index) {
    return *(u32*)((char*)self + ((index - self->base) << 2) + 0x2c);
}
