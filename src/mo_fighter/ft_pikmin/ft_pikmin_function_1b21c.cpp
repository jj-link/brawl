#pragma force_active on
struct DPrefix {
    int a;
    int b;
};

struct D : DPrefix {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
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
    virtual void f15();
};

struct C {
    char pad[0xb0];
    D *d;
};

struct B {
    char pad[0xd8];
    C *c;
};

struct A {
    char pad[0x60];
    B *b;
};

extern "C" void fn_113_1B21C(A *a) {
    a->b->c->d->f15();
}
