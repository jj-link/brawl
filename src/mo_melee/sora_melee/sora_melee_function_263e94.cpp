#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 vf4();
};

struct soOuter {
    u32 pad[3];
    soInner m_inner;
};

extern "C" s32 fn_27_263E94(soOuter* p) {
    return p->m_inner.vf4();
}
