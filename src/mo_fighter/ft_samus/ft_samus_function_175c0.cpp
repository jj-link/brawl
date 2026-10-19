#pragma force_active on
struct C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5(int, int);
    virtual void f6();
    virtual void f7();
};

struct B {
    char pad[0x64];
    C* c;
};

struct A {
    char pad[0xd8];
    B* b;
};

struct Owner {
    char pad[0x60];
    A* a;
};

extern "C" {
int fn_94_175C0(Owner* owner) {
    return owner->a->b->c->f5(-1, 0x10000041);
}
}
