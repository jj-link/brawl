#pragma force_active on
struct A {
    int a, b, c;
};

struct B {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Impl : public A, public B {
};

extern "C" {
void fn_27_292468(Impl& p) {
    B& b = p;
    b.f4();
}
}
