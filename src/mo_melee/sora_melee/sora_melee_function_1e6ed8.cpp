#pragma force_active on
class Base1 {
    int a, b, c, d;
};

class Base2 {
public:
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

class Derived : public Base1, public Base2 { };

extern "C" void fn_27_1E6ED8(Derived* self) {
    self->f13();
}
