#include <types.h>
#pragma force_active on

class Iface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Outer {
    u32 unk0;
    u32 unk4;
    Iface sub;
};

extern "C" void fn_27_9168C(Outer* o) {
    o->sub.f3();
}
