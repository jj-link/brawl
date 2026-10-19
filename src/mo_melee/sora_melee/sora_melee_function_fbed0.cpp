#include <types.h>
#pragma force_active on

class soSubRet {
public:
    u32 m_a;
    u32 m_b;
};

class soSubObj {
public:
    virtual void vfunc0();
    virtual soSubRet* getSub();
};

class soOuterObj {
public:
    u8 m_pad[0x10];
    soSubObj m_sub;
};

extern "C" u32 fn_27_FBED0(soOuterObj* self) {
    return self->m_sub.getSub()->m_b;
}
