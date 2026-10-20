#pragma force_active on
struct B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int);
};

struct A {
    char pad[0x58];
    B* b;
};

struct P {
    char pad[0xd8];
    A* a;
};

extern "C" void fn_104_1F910(void* x, P* p) {
    return p->a->b->v7(1);
}
