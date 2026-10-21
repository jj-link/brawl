#pragma force_active on
struct Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Outer {
    char pad[0xC];
    Iface iface;
};

extern "C" void fn_27_1AAC60(Outer* p) {
    p->iface.f4();
}
