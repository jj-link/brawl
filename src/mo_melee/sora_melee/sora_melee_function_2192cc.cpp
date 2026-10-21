#pragma force_active on

struct Entry {
    unsigned int id;
    unsigned int unknown;
    unsigned short flags;
    unsigned char pad[0x5a];
};

struct Container {
    Entry entries[64];
    unsigned char pad[0x14];
    int count;
};

extern "C" Entry* fn_27_2192CC(Container* self, unsigned int value) {
    if (self->count > 0) {
        Entry* p = self->entries;
        for (int i = 0; i < 64; ++i, ++p) {
            if ((p->flags & 1) && p->id == value)
                return p;
        }
    }
    return 0;
}
