#include <types.h>
#pragma force_active on

struct VBase {
    virtual void f0();
    virtual void* f1(void* p);
};

extern "C" void fn_27_F1D54(VBase* self, u32* src, void* p) {
    u32* dst = (u32*)self->f1(p);
    *dst = *src;
}
