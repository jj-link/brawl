#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int flag, int id);
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

extern "C" int fn_113_1B0CC(A* self, int mode) {
    int flag = 0;
    if (mode == 2) {
        flag = 1;
    }
    return self->b->c->obj->v5(flag, 0x1000000b);
}
