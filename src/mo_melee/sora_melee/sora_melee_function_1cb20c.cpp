#pragma force_active on
struct S {
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
};

struct P {
    virtual void g();
    int pad[3];
};

struct D : P, S {
    virtual void g();
};

extern "C" {
void fn_27_1CB20C(D& p) {
    static_cast<S&>(p).f8();
}
}
