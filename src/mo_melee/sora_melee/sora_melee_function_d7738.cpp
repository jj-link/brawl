#include <types.h>
#pragma force_active on

class soSub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct soOuter {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    soSub sub;
};

extern "C" void fn_27_D7738(soOuter* p) {
    p->sub.f4();
}
