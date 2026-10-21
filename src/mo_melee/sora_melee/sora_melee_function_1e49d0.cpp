#pragma force_active on
struct Pad {
    int a, b, c;
};

struct Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Impl : public Pad, public Iface {
    virtual void f4();
};

extern "C" {
void fn_27_1E49D0(Impl& p) {
    Iface& i = p;
    i.f4();
}
}
