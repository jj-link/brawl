#include <types.h>
#pragma force_active on

class soSubObject {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual s32 vf3();
    virtual void vf4();
    virtual void vf5();
};

class soOuterObject {
public:
    u32 pad[4];
    soSubObject sub;
};

extern "C" {
s32 fn_27_D9E14(soOuterObject* self) {
    return self->sub.vf3();
}
}
