#include <types.h>
#pragma force_active on

class fn_27_Obj {
public:
    virtual ~fn_27_Obj();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void target(bool flag, s32 value);
    u32 m_pad[4];
    struct {
        u8 b0 : 1;
        u8 rest : 7;
    } m_flags;
};

extern "C" void fn_27_B48D0(fn_27_Obj* self, bool flag) {
    self->m_flags.b0 = flag;
    self->target(flag, -1);
}
