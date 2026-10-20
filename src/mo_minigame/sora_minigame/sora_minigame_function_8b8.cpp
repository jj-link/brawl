#pragma force_active on
struct Entry {
    void* key;
    unsigned int value;
};

struct Table {
    unsigned int unused;
    Entry* entries;
    int count;
};

extern "C" bool fn_20_8B8(Table* self, void* key) {
    for (int i = 0; i < self->count; ++i) {
        if (self->entries[i].key == key) {
            --self->count;
            self->entries[i] = self->entries[self->count];
            return true;
        }
    }
    return false;
}
