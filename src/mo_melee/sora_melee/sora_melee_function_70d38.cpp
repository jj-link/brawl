#pragma force_active on
struct C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float v12();
    virtual void v13();
    virtual void v14();
};

struct B {
    char pad[8];
    C* c;
};

struct A {
    char pad[0xd8];
    B* b;
};

struct Self {
    char pad0[0x24];
    float f24;
    char pad1[0x44 - 0x28];
    A* a44;
};

extern "C" {
void fn_27_70D38(Self* self) {
    if (self->a44) {
        self->f24 = self->a44->b->c->v12();
    }
}
}
