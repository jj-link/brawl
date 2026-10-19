#include <types.h>
#pragma force_active on

struct fn27Target {
    u32 m_val;
};

struct fn27Inner {
    virtual void vf0();
    virtual fn27Target* vf1();
};

struct fn27Outer {
    u8 pad[0x2c];
    fn27Inner* m_inner;
};

extern "C" void fn_27_4E310(fn27Outer* self) {
    fn27Target* r = self->m_inner->vf1();
    r->m_val = 0;
}
