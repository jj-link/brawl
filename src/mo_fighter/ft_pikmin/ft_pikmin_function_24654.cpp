#pragma force_active on
struct Sub1 {
    virtual void x0();
    virtual int v3(int);
    virtual void x2();
    virtual void x3();
    virtual int v6();
    virtual void x5();
    virtual void v8();
};

struct Sub2 {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void v12(int);
};

struct Owner {
    char pad0[0x80];
    Sub1 a;
    char pad1[0x7C];
    Sub2 b;
};

extern "C" {
void fn_113_24654(Owner* self) {
    while (self->a.v6() == 0) {
        int r = self->a.v3(0);
        self->b.v12(r);
        self->a.v8();
    }
}
}
