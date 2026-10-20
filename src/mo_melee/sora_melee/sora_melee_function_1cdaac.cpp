#pragma force_active on
class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    char pad[0x10];
    Sub m_sub;
};

extern "C" void fn_27_1CDAAC(Outer* self) {
    self->m_sub.f1();
}
