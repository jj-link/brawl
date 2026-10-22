#pragma force_active on

struct Ret;

struct Base {
    char pad[8];
};

struct D0 : Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Ret* v4();
};

struct Ret {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual int r15();
};

struct C {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual float c9();
};

struct Obj1b;

struct Obj1 {
    virtual void o0();
    virtual void o1();
    virtual Obj1b* o2();
};

struct Obj1b {
    virtual void b0();
    virtual void b1();
    virtual int b2();
};

struct Data {
    D0* d0;
    char pad4[8];
    C* c;
    char pad10[8];
    Obj1* obj1;
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

extern "C" void fn_122_178A0(void*, void*, int, int, float);

extern "C" int fn_122_E074(void* self, Ctx* ctx) {
    Data* data = ctx->data;
    Obj1* obj1 = data->obj1;
    D0* d0 = data->d0;
    void* p = ctx->sub->p;
    float f = data->c->c9();
    int v1 = obj1->o2()->b2();
    int v2 = d0->v4()->r15();
    fn_122_178A0(self, p, v2, v1, f);
    return 1;
}
