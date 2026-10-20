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
    virtual void f();
    char pad[0x10 - 4];
    Sub m_sub;
};

extern "C" void fn_27_1C77C4(Outer* self) {
    self->m_sub.f1();
}
