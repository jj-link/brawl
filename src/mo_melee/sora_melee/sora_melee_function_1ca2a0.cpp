#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
};

class soOuter {
public:
    u8 m_pad[0x10];
    soInner m_inner;
};

extern "C" {
void* fn_27_1CA2A0(soOuter* outer) {
    soInner* inner = &outer->m_inner;
    void* p = inner->vf1();
    return ((void**)p)[1];
}
}
