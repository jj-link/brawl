#include <types.h>
#pragma force_active on

struct Base {
    virtual void f0();
    virtual u32* f1(void* arg);
};

extern "C" void fn_27_1BE378(Base* self, u32* src, void* arg) {
    u32* p = self->f1(arg);
    *p = *src;
}
