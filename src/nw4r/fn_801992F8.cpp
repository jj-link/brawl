#include <types.h>
#pragma force_active on

struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
    virtual void f4();
    virtual void f5();
};

extern "C" void* fn_801992F8(Base* self) {
    return (char*)self->f3() + 4;
}
