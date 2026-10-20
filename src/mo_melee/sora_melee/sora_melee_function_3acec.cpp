#include <types.h>
#pragma force_active on

class fnObjBase {
public:
    virtual void* vf0();
    virtual void* vf1();
};

class fnSelf {
public:
    u8 pad[0x30];
    fnObjBase* m_objA;
    fnObjBase* m_objB;
};

extern "C" void* fn_27_3ACEC(fnSelf* self, u32 unused, u32 flag) {
    if (flag == 1) {
        return self->m_objB->vf1();
    }
    return (u8*)self->m_objA->vf1() + 4;
}
