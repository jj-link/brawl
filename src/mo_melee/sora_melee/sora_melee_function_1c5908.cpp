#pragma force_active on
typedef unsigned int u32;

struct Base0 {
    u32 a, b, c, d;
};

struct Iface {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
};

struct Caller : public Base0, public Iface {
};

extern "C" void fn_27_1C5908(Caller* p) {
    Iface& r = *p;
    r.f8();
}
