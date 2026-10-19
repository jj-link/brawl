#pragma force_active on
struct Vec {
    float x;
    float y;
    float z;
};

struct B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec v4();
};

struct A {
    char pad[0xC];
    B* b;
};

struct Obj {
    char pad[0x180];
    A* a;
};

extern "C" {
float fn_27_263674(Obj* p) {
    return p->a->b->v4().x;
}
}
