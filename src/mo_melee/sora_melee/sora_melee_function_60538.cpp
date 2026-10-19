#include <types.h>
#pragma force_active on

class soBase;

class soBase {
public:
    virtual void vf0();
    virtual soBase* vf1();
    virtual void vf2();
    virtual void vf3();
    u32 m_pad[2];
    float m_value;
};

class soOuter {
public:
    u8 pad[0x40];
    soBase* m_base;
};

extern "C" {
float fn_27_60538(soOuter* self) {
    return self->m_base->vf1()->m_value;
}
}
