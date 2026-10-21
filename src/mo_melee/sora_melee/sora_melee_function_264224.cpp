#pragma force_active on
struct A {
    int x0, x1, x2, x3;
};

struct B {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct D : A, B {
};

extern "C" {
void fn_27_264224(D& p) {
    static_cast<B&>(p).f1();
}
}
