#include <types.h>
#pragma force_active on

struct soSecondaryBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f6();
};

struct soPrimaryBase {
    virtual void g0();
    u32 pad4;
    u32 pad8;
};

struct soDerived : public soPrimaryBase, public soSecondaryBase {
    virtual void g0();
    virtual void f6();
};

extern "C" void fn_27_2EA4FC(soDerived* self) {
    ((soSecondaryBase&)*self).f6();
}
