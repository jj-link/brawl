#pragma force_active on
struct VB {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
};

struct Ifc1 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
};

struct Sub {
    char pad0[0x44];
    Ifc1* p44;
    char pad1[0x0c];
    VB* p54;
};

struct Actor {
    char pad0[0xd8];
    Sub* sub;
};

extern "C" {
void fn_27_18EDF0(void* unused, Actor* actor) {
    if (!actor->sub->p54->v23()) {
        actor->sub->p44->a5();
        actor->sub->p44->a7();
    }
}
}
