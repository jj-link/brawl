#include <types.h>
#pragma force_active on

struct soTarget {
    u8 pad[0x34];
    float m_val;
};

struct soProvider {
    virtual void vf0();
    virtual soTarget* vf1();
    virtual void vf2();
    virtual void vf3();
};

struct soOwner {
    u8 pad[0x18];
    soProvider* m_provider;
};

extern "C" void fn_27_B2EA4(soOwner* self, float value) {
    self->m_provider->vf1()->m_val = value;
}
