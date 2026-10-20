#include <types.h>
#pragma force_active on

struct fn27Obj {
    u8 pad[0x18];
    s32 flags18;
};

extern "C" void* fn_27_1C2C58(fn27Obj* self, s32 idx) {
    s32 i = (self->flags18 >> 28) + idx;
    if (i >= 6) {
        i -= 6;
    }
    return (u8*)self + i * 12 + 0x1c;
}
