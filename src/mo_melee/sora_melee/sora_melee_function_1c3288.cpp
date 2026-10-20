#include <types.h>
#pragma force_active on

class fnSubBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class fnOuter {
public:
    u8 m_pad[0x10];
    fnSubBase m_sub;
};

extern "C" void fn_27_1C3288(fnOuter* p) {
    fnSubBase* s = &p->m_sub;
    s->vf1();
}
