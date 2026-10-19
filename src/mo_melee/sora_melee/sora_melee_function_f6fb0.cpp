#include <types.h>
#pragma force_active on

struct soWorkB {
    s32 m_a;
    s32 m_b;
};

class soIface {
public:
    virtual void v2();
    virtual soWorkB* v3();
};

struct soOuter {
    s32 m_pad[4];
    soIface m_iface;
};

extern "C" s32 fn_27_F6FB0(soOuter* self) {
    soIface* iface = &self->m_iface;
    return iface->v3()->m_b;
}
