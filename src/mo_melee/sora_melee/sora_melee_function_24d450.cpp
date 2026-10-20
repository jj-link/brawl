#pragma force_active on
struct Entry {
    unsigned char pad0[0x25];
    unsigned char state;
    unsigned char pad26[4];
    unsigned char index;
    unsigned char pad2B[0x281];
};

struct Context {
    unsigned char pad0[0xCC];
    Entry* entries;
    unsigned char padD0[0x34];
    int count;
};

extern "C" void fn_27_24D450(Context* self, int* count) {
    *count = 0;
    unsigned int seen = 0;
    for (int i = 0; i < self->count; ++i) {
        Entry* entry = &self->entries[i];
        if (entry->state != 3) {
            unsigned int bit = 1u << entry->index;
            if (!(seen & bit)) {
                seen |= bit;
                ++*count;
            }
        }
    }
}
