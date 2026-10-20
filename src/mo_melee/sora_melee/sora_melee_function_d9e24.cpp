#include <types.h>
#pragma force_active on

class SubObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct OuterObj {
    u32 pad[4];
    SubObj sub;
};

extern "C" {
void fn_27_D9E24(OuterObj* p) {
    p->sub.f3();
}
}
