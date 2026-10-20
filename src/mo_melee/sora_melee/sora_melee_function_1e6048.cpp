#pragma force_active on
struct Prim {
    virtual void p0();
    int pad[3];
};

struct Sec {
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

struct Derived : Prim, Sec {
    virtual void p0();
};

extern "C" void fn_27_1E6048(Derived* p) {
    Sec& s = *p;
    s.f8();
}
