#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ref { u8 kind; u8 pad[3]; u32 value; };
struct Data { u8 pad[8]; Ref base; Ref unused; Ref table; };
struct Obj { u32 pad; Data* data; };
struct Output { u16 v[20]; u16 a, b, c, d; };
extern "C" void* fn_801D3698(u8, u32, void*);
extern "C" int fn_801CCCD4(Obj* __restrict self, Output* out, int index) {
    Data* data = self->data;
    if (*(u8*)fn_801D3698(data->base.kind, data->base.value, &data->base) != 2)
        return 0;
    data = self->data;
    u8* table = (u8*)fn_801D3698(data->table.kind, data->table.value, &data->base);
    if (index >= *table)
        return 0;
    Ref* entry = (Ref*)(table + index * 8 + 4);
    Ref* ref = (Ref*)fn_801D3698(entry->kind, entry->value, &self->data->base);
    Output* result = (Output*)fn_801D3698(ref->kind, ref->value, &self->data->base);
    *out = *result;
    return 1;
}