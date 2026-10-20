#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class soOuter {
public:
    u8 pad[0x10];
    soInner m_inner;
};

extern "C" void fn_27_1C28A4(soOuter* p) {
    p->m_inner.vf1();
}
