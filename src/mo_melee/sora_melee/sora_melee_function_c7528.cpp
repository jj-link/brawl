#include <types.h>
#pragma force_active on

struct fn27C7528Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
};

extern "C" void fn_27_C7528(fn27C7528Base* p) {
    return p->f9();
}
