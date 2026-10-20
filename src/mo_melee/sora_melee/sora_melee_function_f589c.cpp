#pragma force_active on
class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class Outer {
public:
    char pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_F589C(Outer* self) {
    self->m_inner.vf1();
}
