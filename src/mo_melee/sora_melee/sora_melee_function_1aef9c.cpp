#include <types.h>
#pragma force_active on

struct fn_27_1AEF9C_Obj {
    virtual void f0();
    virtual fn_27_1AEF9C_Obj* f3(void* p);
};

extern "C" {
void fn_27_1AEF9C(fn_27_1AEF9C_Obj* self, u32* src, void* arg) {
    fn_27_1AEF9C_Obj* r = self->f3(arg);
    *(u32*)r = *src;
}
}
