#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u8 pad[6];
    u16 version;
    u8 pad2[0x20];
    void* base;
};

extern "C" s32 fn_801D3698(u8, u32, void*);

extern "C" int fn_801C74A4(Obj* __restrict self, u32 index, void* out) {
    void* table = (void*)fn_801D3698(*(u8*)self->base, *(u32*)((u8*)self->base + 4), self->base);
    void* entry;
    if (table == 0) {
        entry = 0;
    } else if (index >= (u32)*(s32*)table) {
        entry = 0;
    } else if (self->version >= 0x101) {
        u8* p = (u8*)table + index * 8;
        entry = (void*)fn_801D3698(*(u8*)(p + 4), *(u32*)(p + 8), self->base);
    } else {
        u8* p = (u8*)table + index * 8;
        entry = (void*)(*(u32*)(p + 8) + (u32)self->base);
    }
    if (entry == 0) {
        return 0;
    }
    u8* e = (u8*)entry;
    void* data = (void*)fn_801D3698(e[12], *(u32*)(e + 16), self->base);
    if (data == 0) {
        return 0;
    }
    *(u32*)out = *(u32*)data;
    ((u8*)out)[4] = ((u8*)data)[4];
    ((u8*)out)[5] = ((u8*)data)[5];
    return 1;
}
