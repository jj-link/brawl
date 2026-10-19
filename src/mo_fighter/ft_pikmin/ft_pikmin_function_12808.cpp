#pragma force_active on
extern "C" void fn_113_12954(void*, void*);

struct Iface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int);
    virtual int v9(int);
    virtual void v10();
    virtual void v11();
};

struct Comp {
    char pad[0x54];
    Iface* iface;
};

struct Owner {
    char pad[0xd8];
    Comp* comp;
};

extern "C" void fn_113_12808(void* a, Owner* b) {
    fn_113_12954(a, b);
    if (b->comp->iface->v9(7) != 0) {
        b->comp->iface->v8(7);
    }
}
