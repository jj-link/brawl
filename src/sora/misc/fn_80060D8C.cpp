#pragma force_active on

typedef unsigned int u32;

struct Entry {
    char pad[0x7C];
    u32 key;
    u32 tail;
};

extern Entry* lbl_805A0164;

struct Manager {
    char pad[0x60];
    Entry* entries;
    char pad64[8];
    int active;
    u32 first;
    u32 last;
};

extern "C" void fn_80062954(Entry*, u32, u32);

static Entry* findEntry(Manager* self, u32 key) {
    Entry* entry;
    if (key && self->active) {
        entry = lbl_805A0164;
        if (entry && entry->key == key)
            return entry;

        entry = &self->entries[self->first];
        for (u32 i = self->first; i <= self->last; ++i, ++entry) {
            if (entry->key == key) {
                lbl_805A0164 = entry;
                return entry;
            }
        }
    }
    return 0;
}

extern "C" void killEffect__5ecMgrFUlUlUl(
    Manager* self, u32 key, u32 a, u32 b
) {
    Entry* entry = findEntry(self, key);
    if (entry) {
        fn_80062954(entry, a, b);
    }
}
