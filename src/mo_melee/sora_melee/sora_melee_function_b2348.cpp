#include <types.h>
#pragma force_active on

struct fn27Target {
    u8 pad[0x10];
    u32 m_10;
};

struct fn27Inner {
    virtual void v0();
    virtual fn27Target* v1(u32 arg);
};

struct fn27Self {
    u8 pad[0x18];
    fn27Inner* m_18;
};

extern "C" {
void fn_27_B2348(fn27Self* self, u32 a, u32 b) {
    fn27Target* t = self->m_18->v1(b);
    t->m_10 = a;
}
}
