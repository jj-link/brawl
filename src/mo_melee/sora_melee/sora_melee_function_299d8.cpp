#include <types.h>
#pragma force_active on

struct SubObj {
    virtual void vf0();
    virtual SubObj* vf1(float v);
    u8 pad[0x10 - 4];
    float m_val;
};

struct Outer {
    u8 pad[0x28];
    SubObj* m_sub;
};

extern "C" void fn_27_299D8(Outer* self, float v) {
    self->m_sub->vf1(v)->m_val = v;
}
