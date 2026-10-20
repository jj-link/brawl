#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

struct fn_27_host {
    u8 pad[0x10];
    soVirtBase m_base;
};

extern "C" void fn_27_1B1648(fn_27_host* self) {
    self->m_base.vf3();
}
