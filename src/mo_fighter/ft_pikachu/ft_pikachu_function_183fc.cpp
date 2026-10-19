#pragma force_active on
struct Obj {
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
    virtual void v16();
    virtual int call(int flag);
};

struct C {
    char pad[0x64];
    Obj* obj;
};

struct B {
    char pad[0xd8];
    C* c;
};

struct A {
    char pad[0x60];
    B* b;
};

extern "C" int fn_98_183FC(A* a) {
    return a->b->c->obj->call(0x12000004);
}
