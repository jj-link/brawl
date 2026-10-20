#include <types.h>
#pragma force_active on

struct fn27Sub {
    virtual fn27Sub* vf0();
    virtual fn27Sub* vf1();
    s32 m_val;
};

struct fn27Outer {
    s32 m_pad[4];
    fn27Sub m_sub;
};

extern "C" {
s32 fn_27_1E64B4(fn27Outer* self) {
    return self->m_sub.vf1()->m_val;
}
}
