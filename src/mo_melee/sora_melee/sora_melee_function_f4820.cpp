#include <types.h>
#pragma force_active on

class soSubObj {
public:
    virtual void* f0();
    virtual struct soRetObj* f1();
    virtual void* f2();
    virtual void* f3();
};

struct soRetObj {
    s32 m_a;
    s32 m_b;
};

struct soOuterObj {
    s32 m_pad[4];
    soSubObj m_sub;
};

extern "C" {
s32 fn_27_F4820(soOuterObj* p) {
    return p->m_sub.f1()->m_b;
}
}
