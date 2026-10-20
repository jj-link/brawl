#pragma force_active on
class soBase2 {
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

class soDerived {
public:
    int m_0;
    int m_4;
    int m_8;
    int m_c;
    soBase2 m_10;
};

extern "C" {
void fn_27_294970(soDerived* p) {
    p->m_10.f13();
}
}
