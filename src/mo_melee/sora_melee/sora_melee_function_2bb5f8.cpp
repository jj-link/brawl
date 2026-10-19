#include <types.h>
#pragma force_active on

struct fn27Val {
    u32 m_value;
};

struct fn27Obj {
    virtual void f0();
    virtual fn27Val* f1(int b);
};

extern "C" {
void fn_27_2BB5F8(fn27Obj* self, fn27Val* src, int b) {
    fn27Val* dst = self->f1(b);
    dst->m_value = src->m_value;
}
}
