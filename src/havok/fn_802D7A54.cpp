#pragma force_active on
struct Inner { char pad[0x1b8]; int v; };
struct Obj { char pad[8]; void* a; Inner* b; Inner* c; };
struct Out { char pad[4]; short s; char c6; char c7; };
struct Ctx {
    int a, b, c, pad;
    int d, e;
    Out* out;
    float f;
    int g;
    Obj* self;
    float h;
};
extern "C" void fn_802F4258(void*, Ctx*);
extern "C" void fn_802E3F48(void*, Ctx*);

extern "C" int fn_802D7A54(Obj* self, int a, int b, int, int d, int e, float* p, Out* out, float h) {
    Ctx x;
    out->s = 0;
    out->c6 = 0;
    out->c7 = 1;
    float t = *p;
    x.a = a;
    x.b = b;
    x.c = 0;
    x.d = d;
    x.e = e;
    x.out = out;
    x.f = t;
    x.self = self;
    x.g = 0;
    x.h = h;
    fn_802F4258(self->a, &x);
    if (self->b->v != 0) fn_802E3F48(self->b, &x);
    if (self->c->v != 0) fn_802E3F48(self->c, &x);
    *p = x.f;
    return x.g;
}
