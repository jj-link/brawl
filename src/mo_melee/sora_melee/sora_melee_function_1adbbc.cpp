#include <types.h>
#pragma force_active on

class fn_27_Iface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class fn_27_Holder {
public:
    u32 pad[4];
    fn_27_Iface iface;
};

extern "C" {
void fn_27_1ADBBC(fn_27_Holder* h) {
    h->iface.f1();
}
}
