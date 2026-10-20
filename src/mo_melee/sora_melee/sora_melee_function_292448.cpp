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
};

class Outer {
public:
    unsigned char pad[0xc];
    Inner m_inner;
};

extern "C" {
void fn_27_292448(Outer* self) {
    self->m_inner.f4();
}
}
