#pragma force_active on

struct B {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct D {
    int pad[3];
    B b;
};

extern "C" void fn_27_1E49A0(D& p) {
    p.b.f4();
}
