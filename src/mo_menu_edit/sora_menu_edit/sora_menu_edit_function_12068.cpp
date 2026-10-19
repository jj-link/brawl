#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    u32 id;
    u8 data[0x40];
};

struct Table {
    Entry* entries;
    u32 count;
    u8 pad[0x5F8];
    u8 active;
};

extern "C" {
void* fn_5_12068(Table* t, u32 key) {
    u32 i;
    if (t->active == 0) {
        return 0;
    }
    for (i = 0; i < t->count; i++) {
        if (key == t->entries[i].id) {
            return &t->entries[i];
        }
    }
    return 0;
}
}
