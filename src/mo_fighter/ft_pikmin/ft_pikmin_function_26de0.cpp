#pragma force_active on
extern "C" void fn_113_263DC(void*, void*);

struct Iface {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5(int, unsigned int) = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18(unsigned int) = 0;
};

struct Mid {
    char pad[0x64];
    Iface* iface;
};

struct Ft {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_113_26DE0(void* a, Ft* b) {
    fn_113_263DC(a, b);
    b->mid->iface->v5(0x5a, 0x20000001);
    b->mid->iface->v5(0x5a, 0x20000000);
    b->mid->iface->v18(0x22000000);
}
