#include <types.h>
#pragma force_active on

class soRetObj {
public:
    s32 m_pad;
    s32 m_value;
};

class soSubObj {
public:
    virtual void vf0();
    virtual soRetObj* vf1();
};

class soOuterObj {
public:
    u8 m_pad[0x10];
    soSubObj m_sub;
};

extern "C" {
s32 fn_27_F7994(soOuterObj* self) {
    return self->m_sub.vf1()->m_value;
}
}
