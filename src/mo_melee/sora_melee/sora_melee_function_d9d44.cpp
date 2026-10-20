#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class soOuter {
public:
    u8 pad[0x10];
};

extern "C" {
void fn_27_D9D44(soOuter* p) {
    soInner& inner = *(soInner*)((char*)p + 0x10);
    inner.vf3();
}
}
