#include <types.h>
#pragma force_active on

struct fn27SubObj {
    virtual void vf0();
    virtual fn27SubObj* vf1();
    s32 m_val;
};

struct fn27Outer {
    u8 m_pad[0x10];
    fn27SubObj m_sub;
};

extern "C" {
    s32 fn_27_F65CC(fn27Outer* p) {
        return p->m_sub.vf1()->m_val;
    }
}
