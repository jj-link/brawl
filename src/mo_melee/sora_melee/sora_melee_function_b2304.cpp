#include <types.h>
#pragma force_active on

struct fn27Sub {
    virtual void v0();
    virtual fn27Sub* v1(u32 x);
    u32 pad4[2];
    u32 unkC;
};

struct fn27Parent {
    u8 pad[0x18];
    fn27Sub* m_sub;
};

extern "C" {
void fn_27_B2304(fn27Parent* self, u32 a, u32 b) {
    fn27Sub* s = self->m_sub->v1(b);
    s->unkC = a;
}
}
