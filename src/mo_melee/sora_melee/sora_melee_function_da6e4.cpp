#include <types.h>
#pragma force_active on

class fn_27_Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(s32 arg);
};

class fn_27_Owner {
public:
    u32 unk0;
    u32 unk4;
    fn_27_Sub* m_8;
};

extern "C" void fn_27_DA6E4(fn_27_Owner* self, s16 arg) {
    self->m_8->v8(arg);
}
