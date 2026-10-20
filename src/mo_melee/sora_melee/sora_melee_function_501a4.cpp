#pragma force_active on
typedef unsigned int u32;

struct Entry {
    unsigned char pad[0x24];
    u32 value;
    u32 unused : 8;
    u32 count : 8;
    u32 state : 15;
    u32 flag : 1;
    u32 tail[2];
};

struct Object {
    unsigned char pad[0xA4];
    Entry* entries;
};

extern "C" u32 fn_27_501A4(Object* object, int index, u32* value) {
    Entry* entry = &object->entries[index];
    u32 count = entry->count;
    if (count == 0) {
        entry->value = *value;
        entry->state = 0;
    } else {
        *value = entry->value;
    }
    ++entry->count;
    return count;
}
