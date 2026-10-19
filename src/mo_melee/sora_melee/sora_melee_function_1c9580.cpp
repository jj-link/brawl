#include <types.h>
#pragma force_active on

struct fn_27_Base {
    virtual void f0();
    virtual u32* f1(void* p);
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_27_1C9580(fn_27_Base* self, u32* src, void* arg) {
    u32* dst = self->f1(arg);
    *dst = *src;
}
