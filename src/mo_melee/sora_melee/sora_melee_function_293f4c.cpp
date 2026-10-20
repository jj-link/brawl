#include <types.h>
#pragma force_active on

struct soRes {
    s32 m_a;
    s32 m_b;
};

class soSubObj {
public:
    virtual soRes* vf0();
    virtual soRes* vf1();
    virtual soRes* vf2();
    virtual soRes* vf3();
};

struct soOuter {
    u8 m_pad[0x10];
    soSubObj m_sub;
};

extern "C" s32 fn_27_293F4C(soOuter* self) {
    return self->m_sub.vf1()->m_b;
}
