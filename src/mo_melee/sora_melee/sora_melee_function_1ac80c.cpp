#pragma force_active on
class fnInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class fnOuter {
public:
    char m_pad[0x10];
    fnInner m_inner;
};

extern "C" {
void fn_27_1AC80C(fnOuter* self) {
    self->m_inner.f3();
}
}
