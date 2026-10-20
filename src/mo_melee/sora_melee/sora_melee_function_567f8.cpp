#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class fnOuter {
public:
    u8 pad[0x3c];
    fnInner* m_inner;
};

extern "C" void fn_27_567F8(fnOuter* self) {
    self->m_inner->vf1();
}
