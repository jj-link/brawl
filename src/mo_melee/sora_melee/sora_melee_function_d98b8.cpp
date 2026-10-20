#include <types.h>
#pragma force_active on

struct Fn27Item {
    u8 data[0x44];
};

struct Fn27Owner {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Fn27Item items[1];
};

extern "C" Fn27Item* fn_27_D98B8(Fn27Owner* self, s32 idx) {
    s32 i = (self->unk8 >> 30) + idx;
    if (i >= 1) {
        i -= 1;
    }
    return &self->items[i];
}
