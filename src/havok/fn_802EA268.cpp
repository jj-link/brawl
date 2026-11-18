#pragma force_active on
#include <types.h>

struct Item {
    char pad[0xC];
    u32 field;
};

struct Obj {
    char pad0[0x26];
    u8 f1 : 2;
    u8 f2 : 2;
    u8 rest : 4;
    char pad1[0x60 - 0x27];
    Item** entries;
    s32 count;
};

inline s32 find(Obj* self, Item* item) {
    s32 n = self->count;
    for (s32 i = 0; i < n; i++) {
        if (self->entries[i] == item) {
            return i;
        }
    }
    return -1;
}

extern "C" void fn_802EA268(Obj* self, Item* item) {
    s32 i = find(self, item);
    self->entries[i] = 0;
    item->field = 0;
    self->f1 = 1;
    self->f2 = 1;
}
