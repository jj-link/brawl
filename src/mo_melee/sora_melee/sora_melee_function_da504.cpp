#pragma force_active on
struct fn27Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void target(short v);
};

struct fn27Outer {
    int pad[2];
    fn27Inner* m_inner;
};

extern "C" void fn_27_DA504(fn27Outer* p, short v) {
    p->m_inner->target(v);
}
