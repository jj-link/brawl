#pragma force_active on
#include <types.h>

struct Entry {
    int kind;
    int value;
    u8 count;
    bool keep;
};

struct Table {
    u8 unk00[0x14];
    Entry* entries;
    u32 unk18;
    u32 count;
};

extern "C" void fn_8015A434(void* arg0, Entry* arg1) {
    Table* self = static_cast<Table*>(arg0);
    u32 off;
    Entry* base;
    Entry* cur;
    u32 i;
    i = 0;
    off = 0;
    u32 n = self->count;

    for (; i < n; i++) {
        base = self->entries;
        cur = (Entry*)((u8*)base + off);
        if (arg1->kind == cur->kind && arg1->value == cur->value) {
            Entry* hit = base + i;
            hit->count++;
            return;
        }
        off += 12;
    }

    if (i < 0xFF) {
        self->entries[i] = *arg1;
        self->entries[i].count = 1;
        self->count++;
        return;
    }

    for (u32 k = 0; k < 254; k++) {
        self->entries[k] = self->entries[k + 1];
    }

    self->entries[254] = *arg1;
    self->entries[254].count = 1;
}
