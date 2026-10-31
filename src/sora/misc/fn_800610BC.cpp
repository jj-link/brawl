#pragma force_active on

struct Entry {
    char pad[0x78];
    unsigned int key;
    unsigned int enabled;
    char pad2[4];
};

struct Manager {
    char pad[0x60];
    Entry* entries;
    char pad1[8];
    int active;
    unsigned int first;
    unsigned int last;
};

extern "C" void fn_80063F28(Entry*, unsigned int);

extern "C" void fn_800610BC(Manager* self, unsigned int key, unsigned int mask, unsigned int rate) {
    if (self->active) {
        unsigned int i = self->first;
        Entry* entry = self->entries + i;
        if (key & 0xFF000000)
            mask |= 0xFF000000;
        key &= mask;
        while (i <= self->last) {
            if (entry->enabled && key == (entry->key & mask))
                fn_80063F28(entry, rate);
            i++;
            entry++;
        }
    }
}
