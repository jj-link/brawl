#pragma force_active on
struct fnInner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct fnOuter {
    char pad[0x10];
    fnInner m_inner;
};

extern "C" void fn_27_1B1518(fnOuter* p) {
    p->m_inner.f3();
}
