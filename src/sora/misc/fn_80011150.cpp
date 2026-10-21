#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0(void* self, u32 arg) = 0;
};

struct Outer {
    u8 pad[0x28];
    Inner* m_28;
};

extern "C" void fn_80011150(Outer* self, u32 arg) {
    self->m_28->v0(self, arg);
}
