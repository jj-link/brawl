#include <types.h>
#pragma force_active on

struct fn_27_Obj {
    virtual void f0();
    virtual fn_27_Obj* f1(fn_27_Obj* other);
};

extern "C" void fn_27_1C8B9C(fn_27_Obj* self, fn_27_Obj* a, fn_27_Obj* b) {
    fn_27_Obj* r = self->f1(b);
    *(u32*)r = *(u32*)a;
}
