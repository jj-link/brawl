#include <types.h>
#pragma force_active on

class soSubObj {
public:
    virtual soSubObj* v0();
    virtual soSubObj* v1();
    s32 m_val;
};

class soOuterObj {
public:
    s32 m_field0;
    s32 m_field4;
    s32 m_field8;
    s32 m_fieldC;
    soSubObj m_sub;
};

extern "C" {
    s32 fn_27_1C1828(soOuterObj* self) {
        return self->m_sub.v1()->m_val;
    }
}
