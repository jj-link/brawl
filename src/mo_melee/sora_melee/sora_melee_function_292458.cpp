#include <types.h>
#pragma force_active on

class soSubObject {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

class soOuter {
public:
    u8 pad[0xc];
    soSubObject sub;
};

extern "C" void fn_27_292458(soOuter* p) {
    p->sub.vf4();
}
