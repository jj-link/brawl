#include <types.h>
#pragma force_active on

class fnSub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct fnOuter {
    u8 pad[0x10];
    fnSub sub;
};

extern "C" {
void fn_27_F802C(fnOuter* p) {
    p->sub.f1();
}
}
