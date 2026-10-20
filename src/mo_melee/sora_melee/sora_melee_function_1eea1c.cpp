#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Object {
    unsigned char pad[0x1c];
    u32 id;
};

struct Key {
    u32 id;
    u32 value;
};

struct Entry {
    unsigned char pad[0x44];
    Object* object;
    u32 value;
};

struct Container {
    unsigned char pad[0x34c];
    Entry* entries;
    u16 count;
};

extern "C" Entry* fn_27_1EEA1C(Container* self, const Key* key) {
    if (key->id) {
        Entry* entry = self->entries;
        for (int i = self->count; i > 0; --i, ++entry) {
            bool match;
            if (entry->object == 0)
                match = false;
            else
                match = key->value == entry->value &&
                        key->id == entry->object->id;
            if (match == true)
                return entry;
        }
    }
    return 0;
}
