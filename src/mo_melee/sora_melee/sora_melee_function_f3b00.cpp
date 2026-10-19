#include <types.h>
#pragma force_active on

struct Vtbl3 {
    virtual void f0();
    virtual u32* f1(void* p);
};

extern "C" void fn_27_F3B00(Vtbl3* self, u32* a, void* b) {
    u32* p = self->f1(b);
    *p = *a;
}
