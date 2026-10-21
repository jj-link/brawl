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

extern "C" int fn_8005EC64(Owner*);
extern "C" void fn_80062954(Record*, int, int);
extern "C" void fn_80064284(Entry*, int);

static inline void findEntry(Owner* self, unsigned int id, Entry*& result)
{
    for (unsigned int i = 0; i < self->count; ++i) {
        if (self->entries[i].active && self->entries[i].id == id) {
            result = &self->entries[i];
            return;
        }
    }
    result = 0;
}

extern "C" void fn_8005F08C(Owner* self)
{
    int id = fn_8005EC64(self);
    if (id < 0x137) {
        Record* record;
        Entry* entry;
        findEntry(self, id, entry);
        if (entry) {
            if (self->enabled) {
                unsigned int i = self->first;
                record = &self->records[i];
                for (; i <= self->last; ++i, ++record) {
                    if (record->active && record->entry->id == (unsigned int)id)
                        fn_80062954(record, 1, 1);
                }
            }
            fn_80064284(entry, 0);
        }
    }
}
