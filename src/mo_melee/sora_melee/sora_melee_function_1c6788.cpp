#include <types.h>
#pragma force_active on

struct Thing {
    u8 pad[0x18];
    s32 f18;
};

extern "C" u8* fn_27_1C6788(Thing* self, s32 idx) {
    s32 i = (self->f18 >> 25) + idx;
    if (i >= 0x20) {
        i -= 0x20;
    }
    return (u8*)self + 0x1c + i * 12;
}
