#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    u32 id;
    u8 data[0x104];
};

struct Table {
    u32 pad[3];
    Entry* entries;
    u32 count;
};

extern "C" {
void* fn_80158CE8(Table* t, u32 key) {
    u32 count = t->count;
    u32 i;
    for (i = 0; i < count; i++) {
        if (key == t->entries[i].id) {
            return &t->entries[i];
        }
    }
    if (count >= 0x60) {
        return t->entries;
    }
    t->entries[count].id = key;
    t->count++;
    return &t->entries[t->count - 1];
}
}