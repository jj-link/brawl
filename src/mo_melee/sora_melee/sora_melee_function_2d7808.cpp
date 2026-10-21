#pragma force_active on

struct Entry {
    int word0;
    int word4;
    int active;
};

struct Container {
    int count;
    Entry entries[64];
};

extern "C" Entry* fn_27_2D7808(Container* self, int index) {
    if (self->count > 0) {
        Entry* entry = self->entries;
        for (int i = 0; i < 64; ++i, ++entry) {
            if (entry->active != 0) {
                if (index <= 0)
                    return entry;
                --index;
            }
        }
    }
    return 0;
}
