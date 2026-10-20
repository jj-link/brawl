#include <types.h>
#pragma force_active on

struct fn27_InnerBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct fn27_Outer {
    u8 pad[0x34];
    fn27_InnerBase* m_inner;
};

extern "C" {
void fn_27_A4950(fn27_Outer* self) {
    self->m_inner->v3();
}
}
