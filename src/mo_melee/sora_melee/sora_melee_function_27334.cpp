#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0();
    virtual fn27Inner* vf3(u32 v);
    virtual void vf1();
    u8 pad[0x39 - 4];
    u8 m_b39;
};

class fn27Outer {
public:
    u8 pad[0x28];
    fn27Inner* m_inner;
};

extern "C" {
void fn_27_27334(fn27Outer* self, u8 a, u32 b) {
    self->m_inner->vf3(b)->m_b39 = a;
}
}
