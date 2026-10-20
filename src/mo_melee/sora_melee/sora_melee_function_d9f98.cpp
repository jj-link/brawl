#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

class fnOuter {
public:
    u32 m_pad0;
    u32 m_pad4;
    fnInner* m_inner;
};

extern "C" {
void fn_27_D9F98(fnOuter* outer) {
    outer->m_inner->vf4();
}
}
