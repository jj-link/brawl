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
    virtual void f8();
};

struct fn27Outer {
    int m_unk0;
    fn27Inner* m_inner;
    int m_a;
    int m_b;
};

extern "C" {
void fn_27_C7920(fn27Outer* self) {
    if (self->m_inner) {
        self->m_inner->f8();
    }
    self->m_a = 0;
    self->m_b = 0;
}
}
