#include <types.h>
#pragma force_active on

struct soIface {
    virtual ~soIface();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct soBaseA {
    virtual void a0();
    s32 x, y, z;
};

struct soDerivedB : public soBaseA, public soIface {
    virtual void f2();
};

extern "C" {
void fn_27_1B1538(soDerivedB* self) {
    soIface& r = *self;
    r.f2();
}
}
