#pragma force_active on
struct A {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual void v7(int, int);
};

struct B {
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int, bool, bool);
};

struct Sub {
    char pad0[0x64];
    A* a;
    char pad1[0x88 - 0x68];
    B* b;
};

struct Outer {
    char pad0[0xd8];
    Sub* sub;
};

extern "C" void fn_121_10CD0(Outer* self, int arg) {
    Sub* sub = self->sub;
    A* a = sub->a;
    B* b = sub->b;
    if (int r = a->v6()) {
        b->v24(r, true, true);
        a->v7(0, arg);
    }
}
