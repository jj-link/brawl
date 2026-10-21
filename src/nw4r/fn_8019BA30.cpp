#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
    virtual void f4();
    virtual void f5();
};

extern "C" char* fn_8019BA30(Inner* self) {
    return self->f3() + 4;
}
