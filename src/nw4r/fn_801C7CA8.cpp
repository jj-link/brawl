#pragma force_active on
#include <types.h>
extern "C" void* fn_801D3698(u8, u32, void*);
struct Base { u8 pad[0x18]; u8 kind; u8 pad2[3]; u32 value; };
struct Self { u8 pad[0x28]; Base* base; };
struct Out { u32 a; u32 b; void* pointer; u32 extra; };
struct Data { u32 a; u32 b; u32 pad; u8 pkind; u8 pad2[3]; u32 pvalue; u8 ekind; u8 pad3[3]; u32 evalue; };
extern "C" int fn_801C7CA8(Self* __restrict self, u32 index, Out* out) {
    Base* base = self->base;
    void* table;
    void* data;
    void* extra;
    u8* entry;
    table = fn_801D3698(base->kind, base->value, (void*)self->base);
    if (!table) return 0;
    u32 count = *(u32*)table;
    if (index >= count) return 0;
    entry = (u8*)table + index * 8;
    data = fn_801D3698(entry[4], *(u32*)(entry + 8), self->base);
    if (!data) return 0;
    Data* d = (Data*)data;
    extra = fn_801D3698(d->ekind, d->evalue, self->base);
    if (!extra) return 0;
    u32 first = d->a;
    base = self->base;
    out->a = first;
    out->b = d->b;
    out->pointer = fn_801D3698(d->pkind, d->pvalue, (void*)base);
    out->extra = *(u32*)extra;
    return 1;
}