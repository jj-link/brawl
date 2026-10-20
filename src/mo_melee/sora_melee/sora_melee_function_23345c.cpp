#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[0x1C];
    u16 value;
};

struct Entry {
    u8 pad[0x90];
    Inner* inner;
};

struct Slot {
    u8 pad[0x4C];
    Entry** entries;
};

extern "C" u16 fn_27_23345C(Slot* self, u32 index) {
    return self->entries[index]->inner->value;
}
