#include <types.h>
#pragma force_active on

class fnInnerBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
};

class fnOuter {
public:
    u8 pad[0x2c];
    fnInnerBase* m_inner;
};

extern "C" {
void fn_27_B7110(fnOuter* p) {
    p->m_inner->vf5();
}
}
