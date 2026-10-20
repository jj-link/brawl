#pragma force_active on
class Inner {
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
};

class Outer {
public:
    int m_pad[4];
    Inner m_inner;
};

extern "C" {
void fn_27_1BB0E4(Outer* p) {
    p->m_inner.f8();
}
}
