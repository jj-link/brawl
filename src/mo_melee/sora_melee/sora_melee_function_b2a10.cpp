#pragma force_active on
struct Entry {
    unsigned char data[0x14];
};

struct Table {
    Entry *entries;
};

struct Owner {
    unsigned char pad[0x1c];
    Table *table;
};

extern "C" {
Entry *fn_27_B2A10(Owner *self, int index)
{
    return &self->table->entries[index];
}
}
