#include <types.h>
#pragma force_active on

class fn_27_96CEC_inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 v8(u32 a, u32 b);
};

class fn_27_96CEC_outer {
public:
    u8 pad[0x28];
    u32 m_28;
    u32 pad2;
    fn_27_96CEC_inner* m_30;
};

extern "C" {
s32 fn_27_96CEC(fn_27_96CEC_outer* self, u32 arg) {
    return self->m_30->v8(self->m_28, arg);
}
}
