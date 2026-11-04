#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct Ctx { u8 pad[0x18]; u8 kind; u32 value; };
struct Obj { u8 pad[0x28]; Ctx* ctx; };
extern "C" void* fn_801D3698(u8, u32, void*);
extern "C" int fn_801C7DA8(Obj* __restrict self, u32 a, u32 b, u32* out) {
    Ctx* c = self->ctx;
    u8* p = (u8*)fn_801D3698(c->kind, c->value, c);
    if (!p) return 0;
    if (a >= *(u32*)p) return 0;
    u8* e = p + a * 8;
    p = (u8*)fn_801D3698(e[4], *(u32*)(e + 8), self->ctx);
    if (!p) return 0;
    p = (u8*)fn_801D3698(p[0x14], *(u32*)(p + 0x18), self->ctx);
    if (!p) return 0;
    if (b >= *(u32*)p) return 0;
    e = p + b * 8;
    p = (u8*)fn_801D3698(e[4], *(u32*)(e + 8), self->ctx);
    if (!p) return 0;
    out[0] = *(u32*)p;
    out[1] = *(u32*)(p + 4);
    return 1;
}