#include <types.h>
#pragma force_active on

struct Ref {
    u8 type;
    u8 flags;
    u16 pad;
    u32 value;
};

struct Object {
    u8 pad0[6];
    u16 version;
    u8 pad8[0x20];
    Ref* data;
};

struct Table {
    u32 count;
    Ref entries[1];
};

extern "C" void* fn_801D3698(u8, u32, Ref*);

extern "C" s32 fn_801C7294(Object* __restrict self, u32 index) {
    Ref* data = self->data;
    Table* table = (Table*)fn_801D3698(data->type, data->value, data);

    if (table == 0) {
        return 0;
    }
    if (index >= table->count) {
        return 0;
    }

    u8 kind;
    if (self->version >= 0x101) {
        Ref* entry = &table->entries[index];
        void* ptr = fn_801D3698(entry->type, entry->value, self->data);
        if (ptr == 0) {
            return 0;
        }
        kind = *(u8*)((char*)ptr + 0x16);
    } else {
        Ref* entry = &table->entries[index];
        kind = entry->flags;
    }

    switch (kind) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        return 0;
    }
}
