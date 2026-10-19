#include <types.h>
#pragma force_active on

struct fn27Src {
    u32 m_0;
};

struct fn27Obj {
    virtual void vf0();
    virtual fn27Src* vf1(void* p);
};

extern "C" void fn_27_1C5044(fn27Obj* self, fn27Src* src, void* arg) {
    fn27Src* dst = self->vf1(arg);
    dst->m_0 = src->m_0;
}
