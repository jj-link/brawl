#pragma force_active on
struct Entry {
    unsigned char pad0[0x25];
    unsigned char state;
    unsigned char pad26[5];
    unsigned char flags;
    unsigned char pad2c[2];
    signed char value;
    unsigned char pad2f[0x27d];
};

struct Context {
    unsigned char pad0[0xcc];
    Entry* entries;
    unsigned char padD0[0x34];
    int count;
};

inline int getValue(Entry* entry) {
    int value = 1;
    if (entry->value >= 0)
        value = entry->value;
    return value;
}

extern "C" int fn_27_24D308(Context* self) {
    int total = 0;
    for (int i = 0; i < self->count; ++i) {
        Entry* entry = &self->entries[i];
        if (entry->state == 0 && ((entry->flags >> 4) & 1)) {
            total += getValue(entry);
        }
    }
    return total;
}
