#pragma force_active on
class IBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct C {
    char pad0[0x58];
    IBase* o;
};

struct B {
    char pad0[0xd8];
    C* c;
};

struct A {
    char pad0[0x60];
    B* b;
};

extern "C" {
void fn_123_9B94(A* a, int x) {
    if ((unsigned int)(x - 0x14e) > 1) {
        return;
    }
    a->b->c->o->v4();
}
}
