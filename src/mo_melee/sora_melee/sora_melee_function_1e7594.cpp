#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class fnOuter {
public:
    u8 pad[0x10];
    fnInner inner;
};

extern "C" void fn_27_1E7594(fnOuter* p) {
    fnInner* ip = &p->inner;
    ip->vf3();
}
