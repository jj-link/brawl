#pragma force_active on
class Sub {
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
    virtual void f14();
    virtual void f15();
};

class Outer {
public:
    virtual void a0();
    int m_a;
    int m_b;
    int m_c;
};

class Derived : public Outer, public Sub {
public:
};

extern "C" {
void fn_27_AFFA0(Derived& self) {
    static_cast<Sub&>(self).f13();
}
}
