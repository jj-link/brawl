#pragma force_active on

struct Pad {
    int a, b, c, d;
};

struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};

struct Impl : public Pad, public Base {
    virtual void f13();
};

extern "C" {
void fn_27_1E5AF0(Impl& p) {
    Base& b = p;
    b.f13();
}
}
