#pragma force_active on
typedef unsigned int u32;

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(u32 a, u32 b);
    virtual void f12();
    virtual void f13(u32 a);
    virtual void f14();
    virtual void f15();
    char pad[0xe4 - 4];
    u32 m_e4;
};

class Self {
public:
    char pad0[0x6c];
    Sub* m_sub;
    char pad1[0x504 - 0x70];
    u32 m_504;
};

extern "C" void fn_10_FA74(Self* self, u32 flag) {
    self->m_sub->f13(self->m_504);
    if (flag != 0) {
        self->m_sub->f11(self->m_sub->m_e4, self->m_504);
    }
}
