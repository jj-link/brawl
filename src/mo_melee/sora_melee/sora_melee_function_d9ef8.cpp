#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class fnOuter {
public:
    u32 unk0;
    u32 unk4;
    fnInner* m_inner;
};

extern "C" {
void fn_27_D9EF8(fnOuter* outer) {
    outer->m_inner->vf4();
}
}
