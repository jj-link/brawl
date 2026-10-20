#include <types.h>
#pragma force_active on

class soSubVirt {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct soOuter {
    u8 pad[0x10];
    soSubVirt sub;
};

extern "C" void fn_27_1C81A8(soOuter* p) {
    soSubVirt* s = &p->sub;
    s->vf1();
}
