#pragma force_active on
struct C {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5(int, int) = 0;
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

extern "C" void fn_98_1472C(Owner* o, int x) {
    o->a->b->c->v5(x, 0x10000005);
}
