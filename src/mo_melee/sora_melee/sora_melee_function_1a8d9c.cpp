#pragma force_active on
struct A {
    int x, y, z;
};

struct B {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct D : A, B {
};

extern "C" void fn_27_1A8D9C(D& p) {
    static_cast<B&>(p).f4();
}
