#include <types.h>
#pragma force_active on

class SoW {
public:
    u32 m_pad0;
    u32 m_pad1;
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual u32 f14();
};

class SoB {
public:
    u8 m_pad[0xb8];
    SoW* m_w;
};

class SoA {
public:
    u8 m_pad[0xd8];
    SoB* m_b;
};

class SoV {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    u8 m_pad0[0x1c - 0x04];
    SoA* m_a;
    u8 m_pad1[0x28 - 0x20];
    s32 m_count;
};

extern "C" void fn_27_14FE34(SoV* self) {
    if (self->m_a->m_b->m_w->f14() != 1) {
        if (self->m_count > 0) {
            self->m_count -= 1;
            if (self->m_count <= 0) {
                self->f4();
            }
        }
    }
}
