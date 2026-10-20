#pragma force_active on
struct Z {
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
    virtual void v17(void* p);
    virtual void v18();
    virtual void v19();
};

struct Q { char pad[0x84]; Z* z84; };
struct P { char pad[0xd8]; Q* qd8; };
struct A { char pad[0x60]; P* p60; };
struct R { char pad[0x28]; void* w28; };
struct C { char pad[0x8]; R* r8; };

extern "C" void fn_27_6654(A* a, void* unused, C* c) {
    a->p60->qd8->z84->v17(c->r8->w28);
}
