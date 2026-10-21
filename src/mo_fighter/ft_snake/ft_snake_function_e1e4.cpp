#pragma force_active on

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual Obj* f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual Obj* f15();
};

struct Pad {
    int x;
    int y;
};

struct PadIface : Pad {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Obj* f4();
};

struct Data {
    PadIface* a;
    char p4[8];
    Obj* c;
    char p10[8];
    Obj* d;
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

extern "C" void fn_122_22864(void*, void*, void*, void*, float);

extern "C" int fn_122_E1E4(void* self, Ctx* ctx) {
    Data* data = ctx->data;
    Obj* d = data->d;
    PadIface* a = data->a;
    void* p = ctx->sub->p;
    float f = data->c->f9();
    Obj* t = d->f2()->f2();
    d = t;
    Obj* y = a->f4()->f15();
    fn_122_22864(self, p, y, d, f);
    return 1;
}
