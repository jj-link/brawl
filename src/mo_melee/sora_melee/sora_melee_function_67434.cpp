#include <types.h>
#pragma force_active on

class soStopModuleImpl {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    void activate();
    u8 m_pad[0x1c - 0x04];
    u8 m_flags;
};

void soStopModuleImpl::activate() {
    vfunc3();
    m_flags &= ~0x04;
}
