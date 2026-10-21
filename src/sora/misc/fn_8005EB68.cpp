#pragma force_active on
struct Entry {
    int active;
    unsigned char pad04[0x0C];
    unsigned int id;
    unsigned int pad14;
};

struct Record {
    unsigned char pad00[0x30];
    Entry* entry;
    unsigned char pad34[0x48];
    int active;
    unsigned int pad80;
};

struct Owner {
    unsigned char pad00[0x58];
    Entry* entries;
    unsigned int count;
    Record* records;
    unsigned char pad64[8];
    int enabled;
    unsigned int first;
    unsigned int last;
};

extern "C" void fn_80062954(Record*, int, int);
extern "C" void fn_80064284(Entry*, int);

static inline Entry* findEntry(Owner* self, unsigned int id)
{
    for (unsigned int i = 0; i < self->count; ++i) {
        if (self->entries[i].active && self->entries[i].id == id)
            return &self->entries[i];
    }
    return 0;
}

extern "C" void fn_8005EB68(Owner* self, unsigned int id)
{
    Entry* entry = findEntry(self, id);
    if (entry) {
        if (self->enabled) {
            Record* record;
            unsigned int i = self->first;
            record = &self->records[i];
            for (; i <= self->last; ++i, ++record) {
                if (record->active && record->entry->id == id)
                    fn_80062954(record, 1, 1);
            }
        }
        fn_80064284(entry, 0);
    }
}
