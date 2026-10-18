#include <types.h>
#pragma force_active on

class soVirtIface {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8(s16 p) = 0;
};

struct soOwner {
    u32 unk0;
    u32 unk4;
    soVirtIface* m_iface;
};

extern "C" {
void fn_27_11B818(soOwner* self, s16 p) {
    self->m_iface->vf8(p);
}
}
