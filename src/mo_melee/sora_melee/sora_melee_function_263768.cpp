#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Mid {
    char pad[0x1c];
    Inner* inner;
};

struct Outer {
    char pad[0x180];
    Mid* mid;
};

extern "C" void fn_27_263768(Outer* p) {
    return p->mid->inner->v6();
}
