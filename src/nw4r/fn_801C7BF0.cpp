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

extern "C" s32 fn_801C7BF0(Object* __restrict self, u32 index) {
    Table* table = (Table*)fn_801D3698(
        self->data->type, self->data->value, self->data);

    void* ptr;
    if (table == 0) {
        ptr = 0;
        goto check_ptr;
    }
    if (index >= table->count) {
        ptr = 0;
        goto check_ptr;
    }

    if (self->version >= 0x101) {
        Ref* entry = &table->entries[index];
        ptr = fn_801D3698(entry->type, entry->value, self->data);
    } else {
        Ref* entry = &table->entries[index];
        ptr = (void*)(entry->value + (u32)self->data);
    }

check_ptr:
    if (ptr == 0) {
        return 0;
    }
    return *(s32*)((char*)ptr + 0x20);
}
