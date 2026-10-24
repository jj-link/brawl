#include <types.h>
#pragma force_active on

struct Entry {
    u8 kind;
    u8 pad[3];
    u32 value;
};

struct Data {
    u32 unk0;
    u32 unk4;
    u32 count;
    Entry entries[1];
};

struct Table {
    u32* data;

    Table(u32* p) : data(p) {}

    u32 size() const {
        return *data;
    }
};

struct Object {
    s32 valid;
    u32 unk4;
    Data* data;
};

extern "C" s32 fn_801D3698(u8, u32, void*);
extern "C" void fn_801D36BC(void*, s32);
extern "C" s32 fn_801D36C4(void*, s32, s32);

extern "C" s32 fn_801BC2A8(Object self, s32 arg1, u32 index, s32 arg3) {
    char sp8[8];

    if (self.valid == 0) {
        return 0;
    }

    Data* base = self.data;
    if (base == 0) {
        return 0;
    }

    Table table(&base->count);
    if (index >= table.size()) {
        return 0;
    }

    Entry* entry = &base->entries[index];
    s32 value = fn_801D3698(entry->kind, entry->value, table.data);
    if (value == 0) {
        return 0;
    }

    fn_801D36BC(sp8, value);
    return fn_801D36C4(sp8, arg1, arg3);
}
