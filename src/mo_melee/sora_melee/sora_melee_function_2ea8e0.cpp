#pragma force_active on
struct Base1 {
    int data[4];
};

struct Base2 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Derived : public Base1, public Base2 {
};

extern "C" {
void fn_27_2EA8E0(Derived& p) {
    static_cast<Base2&>(p).f3();
}
}
