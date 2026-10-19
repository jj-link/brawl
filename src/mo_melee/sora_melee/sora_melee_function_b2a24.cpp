#include <types.h>
#pragma force_active on

struct soSubObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct soOuterObj {
    u8 pad[0x18];
    soSubObj* m_sub;
};

extern "C" void fn_27_B1C84();

extern "C" void fn_27_B2A24(soOuterObj* p) {
    p->m_sub->vf1();
    fn_27_B1C84();
}
