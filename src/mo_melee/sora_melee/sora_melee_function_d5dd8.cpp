#pragma force_active on
struct Pad {
    int a;
    int b;
    int c;
};

class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class Derived : public Pad, public Base {
};

extern "C" void fn_27_D5DD8(Derived* self) {
    Base& b = *self;
    b.f4();
}
