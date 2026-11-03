#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
struct Ctx { u8 pad[8]; u8 kind; u32 value; };
struct Inner { u8 pad[0x28]; Ctx* ctx; };
extern "C" s32 fn_801D3698(u8, u32, void*);
extern "C" int fn_801C773C(Inner* __restrict self, u32 idx, int* out) {
    Ctx* c = self->ctx;
    void* r = (void*)fn_801D3698(c->kind, c->value, c);
    void* v;
    if (r == 0) v = 0;
    else if (idx >= *(u32*)r) v = 0;
    else { u8* e = (u8*)r + idx * 8; v = (void*)fn_801D3698(e[4], *(u32*)(e+8), self->ctx); }
    if (!v) return 0;
    *out = *(u32*)((u8*)v+4);
    return 1;
}