#include <types.h>
#pragma force_active on

class soVirt {
public:
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual s32 f18();
};

struct soHolder {
    u8 pad0[0x8];
    soVirt* m_obj8;
    u8 pad1[0x3c - 0xc];
    soVirt* m_obj3c;
};

struct soSelf {
    u8 pad[0xd8];
    soHolder* m_holder;
};

extern "C" {
void fn_27_179494(void*, soSelf* self, s32 type) {
    switch (type) {
    case 14:
        if (self->m_holder->m_obj8->f18() == 0) {
            self->m_holder->m_obj3c->f11(0, 0);
        }
        break;
    default:
        self->m_holder->m_obj3c->f11(0, 0);
        break;
    }
}
}
