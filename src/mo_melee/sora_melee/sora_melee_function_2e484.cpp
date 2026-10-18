#include <types.h>
#pragma force_active on

struct fnInner {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5(void* self, u32 arg) = 0;
};

struct fnOuter {
    u8 pad[0x44];
    fnInner* m_44;
};

extern "C" void fn_27_2E484(fnOuter* self, u32 arg) {
    self->m_44->v5(self, arg);
}
