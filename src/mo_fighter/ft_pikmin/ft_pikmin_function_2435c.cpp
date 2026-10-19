#pragma force_active on

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void target();
};

struct Main {
    Obj m_a;
    char pad_a[0x7C];
    Obj m_b;
    char pad_b[0x7C];
    Obj m_c;
};

extern "C" void fn_113_2435C(Main* self) {
    self->m_a.target();
    self->m_b.target();
    self->m_c.target();
}
