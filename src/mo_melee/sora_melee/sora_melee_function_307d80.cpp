#include <types.h>
#pragma force_active on

class Base {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
};

struct Mid {
    char pad[0x3c];
    Base* b;
};

struct Outer {
    char pad[0xd8];
    Mid* m;
};

extern "C" {
void fn_27_307D80(void* unused, Outer* p) {
    return p->m->b->vf13();
}
}
