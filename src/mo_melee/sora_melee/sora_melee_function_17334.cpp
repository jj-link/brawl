#include <types.h>
#pragma force_active on

class soSubWork {
public:
    virtual void vf0();
    virtual soSubWork* vf1();
    u8 m_pad[0xc];
    float m_value;
};

class soOwner {
public:
    u8 m_pad[0x8c];
    soSubWork* m_sub;
};

extern "C" {
void fn_27_17334(soOwner* self, float value) {
    soSubWork* sub = self->m_sub;
    soSubWork* target = sub->vf1();
    target->m_value = value;
}
}
