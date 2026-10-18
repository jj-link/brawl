#pragma force_active on
struct Pad {
    int x;
    int y;
};

struct Iface {
    virtual void f0();
    virtual void f1();
    virtual Iface* f2();
    virtual void f3();
    virtual Iface* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual Iface* f15();
};

struct PadIface : Pad {
    virtual void f0();
    virtual void f1();
    virtual Iface* f2();
    virtual void f3();
    virtual Iface* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual Iface* f15();
};

struct Data {
    Iface* a;
    char pad[0x14];
    Iface* b;
};

struct Sub {
    char pad[0x28];
    void* p;
};

struct Ctx {
    char pad0[8];
    Sub* sub;
    char pad1[0xd8 - 0xc];
    Data* data;
};

extern "C" void fn_122_1A430(void* self, void* a, Iface* b, Iface* c);

extern "C" int fn_122_E140(void* self, Ctx* ctx) {
    Iface* t;
    Data* data = ctx->data;
    PadIface* a = (PadIface*)data->a;
    void* p = ctx->sub->p;
    t = data->b->f2()->f2();
    Iface* u = a->f4()->f15();
    fn_122_1A430(self, p, u, t);
    return 1;
}
