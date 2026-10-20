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
    virtual void vf6();
};

class soOuter {
public:
    u32 m0;
    u32 m4;
    soInner* m8;
};

extern "C" {
void fn_27_DA358(soOuter* self) {
    self->m8->vf4();
}
}
