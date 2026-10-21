#pragma force_active on
struct Pad {
    int a, b, c, d;
};

struct Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Impl : public Pad, public Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

extern "C" {
void fn_27_1E6158(Impl& p) {
    Iface& i = p;
    i.f1();
}
}
