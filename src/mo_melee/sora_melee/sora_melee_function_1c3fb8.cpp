#include <types.h>
#pragma force_active on

class soInnerObj {
public:
    virtual void* getA();
    virtual void* getB();
};

struct soRetObj {
    s32 m_0;
    s32 m_4;
};

class soOuterObj {
public:
    u8 m_pad[0x10];
    soInnerObj m_inner;
};

extern "C" s32 fn_27_1C3FB8(soOuterObj* self) {
    soRetObj* ret = (soRetObj*)self->m_inner.getB();
    return ret->m_4;
}
