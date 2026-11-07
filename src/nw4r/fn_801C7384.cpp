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
extern "C" int fn_801C7384(Obj* __restrict self, u32 index, u32* out) {
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
    if (entry == 0) return 0;
    u8* e = (u8*)entry;
    out[0] = *(u32*)(e + 4);
    out[1] = *(u32*)(e + 8);
    out[2] = e[0x15];
    out[3] = e[0x14];
    out[4] = e[0x17];
    if (self->version >= 0x102) {
        out[5] = e[0x28];
        out[6] = e[0x29];
    } else {
        out[5] = 1;
        out[6] = 0;
    }
    return 1;
}