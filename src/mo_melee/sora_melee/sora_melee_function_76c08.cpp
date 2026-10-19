#include <types.h>
#pragma force_active on

extern "C" void fn_27_AB638();

struct Inner {
    virtual void vf0();
    virtual void vf1(int);
};

struct Outer {
    u32 unk0;
    Inner* m_4;
    int m_8;
};

extern "C" void fn_27_76C08(Outer* self, int idx) {
    Inner* p = self->m_4;
    int v = (idx <= -1) ? self->m_8 : idx;
    p->vf1(v);
    fn_27_AB638();
}
