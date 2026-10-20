#include <types.h>
#pragma force_active on

class fnSub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

struct fnOuter {
    u8 pad[0x10];
    fnSub sub;
};

extern "C" {
void fn_27_EFE88(fnOuter* o) {
    o->sub.vf8();
}
}
