#pragma force_active on
typedef unsigned int u32;

struct Entry {
    u32 value;
    u32 unknown;
};

struct Table {
    Entry* entries;
    u32 count;
};

struct Data {
    char pad[0x70];
    Table* table;
};

struct Object {
    char pad[0x2184];
    Data* data;
};

extern "C" char lbl_41_data_455E[];
extern "C" void wnemReport__FPCce(const char*, ...);

extern "C" bool fn_41_31960(Object* self, u32 index) {
    Table* table = self->data->table;
    if (!table)
        return false;

    if (index >= table->count) {
        wnemReport__FPCce(lbl_41_data_455E, index, table->count);
        return false;
    }

    return table->entries[index].value != 0;
}
