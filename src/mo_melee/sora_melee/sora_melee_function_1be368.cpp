#pragma force_active on
struct Iface {
    virtual void f0();
    virtual void f1();
};

struct Outer {
    int a, b, c, d;
    Iface iface;
};

extern "C" void fn_27_1BE368(Outer* p) {
    p->iface.f1();
}
