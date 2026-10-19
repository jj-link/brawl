#include <types.h>
#pragma force_active on

struct fn27Obj {
    virtual void f0();
    virtual fn27Obj* f1(void* p);
};

extern "C" {
fn27Obj* fn_27_F8A20(fn27Obj* self, const fn27Obj* src, void* p) {
    fn27Obj* r = self->f1(p);
    *reinterpret_cast<u32*>(r) = *reinterpret_cast<const u32*>(src);
    return r;
}
}
