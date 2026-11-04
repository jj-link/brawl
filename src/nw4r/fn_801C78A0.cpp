#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Ref { u8 pad[0x20]; u8 kind; u32 value; };
struct Obj { u8 pad[0x28]; Ref* data; };

extern "C" s32 fn_801D3698(u8, u32, void*);

extern "C" int fn_801C78A0(Obj* __restrict self, u32 index, u32* out) {
    Ref* c = self->data;
    void* table = (void*)fn_801D3698(c->kind, c->value, c);
    void* entry;
    if (table == 0) {
        entry = 0;
    } else if (index >= *(u32*)table) {
        entry = 0;
    } else {
        u8* p = (u8*)table + index * 8;
        entry = (void*)fn_801D3698(p[4], *(u32*)(p + 8), self->data);
    }
    if (entry == 0) return 0;
    u8* e = (u8*)entry;
    u32* data = (u32*)fn_801D3698(e[0x20], *(u32*)(e + 0x24), self->data);
    if (data == 0) return 0;
    out[1] = fn_801D3698(e[8], *(u32*)(e + 0xc), self->data);
    out[2] = *(u32*)(e + 0x10);
    out[3] = *(u32*)(e + 0x14);
    out[4] = *(u32*)(e + 0x18);
    out[5] = *(u32*)(e + 0x1c);
    out[0] = *data;
    return 1;
}
