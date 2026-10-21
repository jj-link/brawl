#include <types.h>
#pragma force_active on

struct ftDataTable {
    u32 pad[0x18C / 4];
    u32 entries[1];
};

extern "C" u32 fn_8004A5C8(ftDataTable* self, u32 index) {
    return self->entries[index];
}
