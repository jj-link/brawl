#pragma force_active on
struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Base {
    virtual void b0();
    int pad[3];
};

struct Derived : public Base, public Sub {
    virtual void f5();
};

extern "C" void fn_27_1B1528(Derived* p) {
    Sub& s = *p;
    s.f3();
}
