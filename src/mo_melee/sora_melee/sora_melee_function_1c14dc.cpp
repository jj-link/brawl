#pragma force_active on
struct Pad {
    int a, b, c, d;
};

struct Iface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Impl : public Pad, public Iface {
};

extern "C" void fn_27_1C14DC(Impl* p) {
    Iface& i = *p;
    i.v1();
}
