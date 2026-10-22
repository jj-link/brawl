#pragma force_active on
extern "C" void fn_801AC7C0(void*);
extern "C" void fn_801A12AC(unsigned int);

class VirtObj {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6(void*) = 0;
    virtual void f7(void*) = 0;
};

class Owner {
public:
    char pad[0xE8];
    VirtObj* m_virt;
    int unkEC;
    int unkF0;
};

extern "C" void fn_801ACE98(Owner* self) {
    fn_801AC7C0(self);
    if (self->unkF0 & 1) {
        self->m_virt->f6(&self->unkEC);
        self->m_virt->f7(&self->unkEC);
    } else {
        self->m_virt->f6(0);
        self->m_virt->f7(0);
    }
    fn_801A12AC(4);
}
