#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct Ctx { u8 pad[0x20]; u8 kind; u32 value; };
struct Obj { u8 pad[0x28]; Ctx* ctx; };
extern "C" void* fn_801D3698(u8, u32, void*);
extern "C" int fn_801C79B0(Obj* __restrict self, u32 a, u32 b, u32* out) {
    Ctx* c = self->ctx;
    u8* p = (u8*)fn_801D3698(c->kind, c->value, c);
    u8* v;
    if (!p) v = 0;
    else if (a >= *(u32*)p) v = 0;
    else { u8* e = p + a * 8; v = (u8*)fn_801D3698(e[4], *(u32*)(e + 8), self->ctx); }
    if (!v) return 0;
    u8* p2 = (u8*)fn_801D3698(v[0x20], *(u32*)(v + 0x24), self->ctx);
    if (!p2) return 0;
    if (b >= *(u32*)p2) return 0;
    u8* e = p2 + b * 8;
    p = (u8*)fn_801D3698(e[4], *(u32*)(e + 8), self->ctx);
    if (!p) return 0;
    out[0] = *(u32*)p;
    out[1] = *(u32*)(p + 4);
    out[2] = *(u32*)(p + 8);
    out[3] = *(u32*)(p + 0xc);
    out[4] = *(u32*)(p + 0x10);
    return 1;
}
