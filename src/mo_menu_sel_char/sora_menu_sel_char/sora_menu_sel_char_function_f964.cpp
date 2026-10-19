#pragma force_active on
struct Sub {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void f34(int a, int b);
    virtual void f38();
    virtual void f3c(int a);
    char pad[0xe4 - 4];
    int m_e4;
};

struct Self {
    char pad0[0x6c];
    Sub* m_6c;
    char pad1[0x500 - 0x70];
    int m_500;
};

extern "C" void fn_10_F964(Self* self, int flag) {
    self->m_6c->f3c(self->m_500);
    if (flag) {
        self->m_6c->f34(self->m_6c->m_e4, self->m_500);
    }
}
