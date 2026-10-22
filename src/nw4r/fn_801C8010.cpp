#include <types.h>
#pragma force_active on

extern int lbl_805A05F0;
extern int lbl_805A05F4;

struct Ref {
    u8 type;
    u8 flags;
    u16 pad;
    u32 value;
};

union Value {
    Ref ref;
    u64 raw;
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

extern "C" u64 fn_801C8010(Object* __restrict self, u32 index) {
    Ref* data = self->data;
    Table* table = (Table*)fn_801D3698(data->type, data->value, data);
    if (table == 0) {
        return ((u64)(u32)lbl_805A05F0 << 32) | (u32)lbl_805A05F4;
    }
    if (index >= table->count) {
        return ((u64)(u32)lbl_805A05F0 << 32) | (u32)lbl_805A05F4;
    }
    if (self->version >= 0x101) {
        Ref* entry = &table->entries[index];
        void* ptr = fn_801D3698(entry->type, entry->value, self->data);
        Value value;
        if (ptr == 0) {
            ((u32*)&value)[0] = lbl_805A05F0;
            ((u32*)&value)[1] = lbl_805A05F4;
        } else {
            ((u32*)&value)[0] = *(u32*)((char*)ptr + 0x18);
            ((u32*)&value)[1] = *(u32*)((char*)ptr + 0x1C);
        }
        return value.raw;
    }
    Ref* entry = &table->entries[index];
    Value value;
    value.ref.type = entry->type;
    value.ref.flags = entry->flags;
    value.ref.value = entry->value + 0x1C;
    return value.raw;
}
