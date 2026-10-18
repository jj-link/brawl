#pragma force_active on
struct B {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};

struct A {
    char pad[0x3c];
    B* b;
};

struct Owner {
    char pad[0xd8];
    A* a;
};

extern "C" void fn_115_10CA0(void* unused, Owner* o) {
    o->a->b->v13();
}
