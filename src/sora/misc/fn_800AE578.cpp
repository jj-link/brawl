#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    u32 id;
    u8 data[0x60];
};

struct Table {
    Entry* entries;
    u8 pad0[0x2EF0];
    u32 count;
    u8 pad1[0xFB0];
    u8 flag1;
    u8 pad2[7];
    u8 flag2;
};

extern "C" {
void* fn_800AE578(Table* self, u32 id) {
    u32 i;
    if (self->flag1 == 0 && self->flag2 == 0) {
        return 0;
    }
    for (i = 0; i < self->count; i++) {
        if (id == self->entries[i].id) {
            return &self->entries[i];
        }
    }
    return 0;
}
}