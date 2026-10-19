#include <types.h>
#pragma force_active on

struct fn_27Base {
    virtual void f0();
    virtual void* f1(void* p);
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_27_1E6168(fn_27Base* self, fn_27Base* src, void* arg) {
    void* dst = self->f1(arg);
    *reinterpret_cast<u32*>(dst) = *reinterpret_cast<u32*>(src);
}
