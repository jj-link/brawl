#include <types.h>
#pragma force_active on

struct fn_27_Obj {
    virtual void f0();
    virtual fn_27_Obj* f1(void* p);
};

extern "C" void fn_27_294FE8(fn_27_Obj* self, u32* src, void* other) {
    fn_27_Obj* r = self->f1(other);
    *(u32*)r = *src;
}
