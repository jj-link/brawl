#include <types.h>
#pragma force_active on

class fnSub {
public:
    virtual void f0();
    virtual void f1();
};

class fnOuter {
public:
    u32 pad[4];
    fnSub sub;
};

extern "C" {
void fn_27_1C4650(fnOuter* p) {
    p->sub.f1();
}
}
