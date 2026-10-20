#include <types.h>
#pragma force_active on

class WorkObj {
public:
    virtual ~WorkObj() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual s32 set(u32 arg, s32 value) = 0;   // vtable 0x24
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual s32 get() = 0;                     // vtable 0x30
};

class Owner {
public:
    u8 pad[0x28];
    u32 m_id;
    u32 m_pad;
    WorkObj* m_primary;
    u32 m_pad2;
    WorkObj* m_secondary;
};

extern "C" s32 fn_27_96C50(Owner* self, s32 value) {
    if (value < self->m_primary->get()) {
        return self->m_primary->set(self->m_id, value);
    }
    WorkObj* target = self->m_secondary;
    if (target) {
        return target->set(self->m_id, value);
    }
    return 0;
}
