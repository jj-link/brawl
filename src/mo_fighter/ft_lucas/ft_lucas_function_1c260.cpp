#include <types.h>
#pragma force_active on

struct LucasIndexed {
    u8 pad[0x18];
    s32 base;
    u8 pad2[0x24 - 0x1C];
    u32 items[1];
};

extern "C" u32 fn_114_1C260(LucasIndexed* self, s32 unused, s32 index) {
    return self->items[index - self->base];
}
