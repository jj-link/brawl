#include <types.h>
#pragma force_active on

class stObj {
public:
    virtual void v0();
    virtual stObj* v1();
    virtual void v2();
    virtual void v3();
    u8 pad[0x34 - 4];
    u32 m_flags : 9;
};

class stOwner {
public:
    u8 pad[0x30];
    stObj* m_obj;
};

extern "C" void fn_27_3AF34(stOwner* self, int unused, u32 flag) {
    stObj* o = self->m_obj->v1();
    o->m_flags = flag;
}
