#include <types.h>
#pragma force_active on

struct soRetVirt {
    s32 a;
    s32 b;
};

class soSubVirt {
public:
    virtual void f0();
    virtual soRetVirt* f1();
    virtual void f2();
    virtual void f3();
};

struct soOuterVirt {
    u8 pad[0x10];
    soSubVirt sub;
};

extern "C" s32 fn_27_2EB5DC(soOuterVirt* p) {
    soSubVirt* s = &p->sub;
    return s->f1()->b;
}
