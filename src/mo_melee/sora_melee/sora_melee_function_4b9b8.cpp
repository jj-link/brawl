#include <types.h>
#pragma force_active on

class SubObj {
public:
    virtual void vf0();
    virtual s32* vf1();
    virtual void vf2();
    virtual void vf3();
};

class Owner {
public:
    char pad[0x2c];
    SubObj* m_sub;
};

extern "C" {
s32 fn_27_4B9B8(Owner* self) {
    return *self->m_sub->vf1() != 0;
}
}
