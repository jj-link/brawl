#pragma force_active on
struct Entry {
    unsigned char active;
    unsigned char pad[11];
    int state;
    unsigned char tail[16];
};

struct Pool {
    unsigned char pad[12];
    unsigned int count;
    Entry* entries;
    unsigned char gap[8];
    unsigned int used;
};

extern "C" void fn_40_14628(Pool* self) {
    for (unsigned int i = 0; i < self->count; ++i) {
        Entry* entry = &self->entries[i];
        if (entry->active) {
            switch (entry->state) {
            case 7:
                entry->state = 8;
            case 8:
                self->entries[i].active = 0;
                --self->used;
                break;
            }
        }
    }
}
