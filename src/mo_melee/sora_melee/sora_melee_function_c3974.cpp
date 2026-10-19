#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_C40F4(void* self);

class soInnerObj {
public:
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
};

struct soOuterObj {
    u8 pad[0xc];
    soInnerObj* inner;
};

extern "C" {
u32 fn_27_C3974(soOuterObj* self) {
    return fn_27_C40F4(self->inner->vf1());
}
}
