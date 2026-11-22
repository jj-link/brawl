#include <types.h>
#pragma force_active on

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();

struct Entry {
    u8 pad[0x78];
    u8 flag : 1;
    u8 rest : 7;
    u8 data[0x19F];
};

struct Parent {
    u8 pad[0x70];
    Entry entries[5];
};

extern "C" u8 fn_800CB250(Parent* self, s32 arg1) {
    u8 index = fn_800C8548();
    Entry* entry;

    if (index == 0xFF) {
        u8 local = fn_800C851C();
        if (local == 0xFF)
            local = 4;
        entry = &self->entries[local];
    } else {
        entry = &self->entries[index];
        if (!entry->flag) {
            u8 local = fn_800C851C();
            if (local == 0xFF)
                local = 4;
            entry = &self->entries[local];
        }
    }

    s32 count;
    for (count = 0; count < 4; count++) {
        if (((u8*)entry)[0xE4 + count * 10] != 0)
            break;
    }

    if (arg1 >= count)
        return 0;
    return (u8)(arg1 + 1);
}