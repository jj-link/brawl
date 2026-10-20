#include <types.h>
#pragma force_active on

struct IFaceDummy {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual s32 call(u32* a, s32 b, u16* c, s8 d);
};

struct OuterObj {
    u8 pad[8];
    IFaceDummy* m_iface;
};

extern "C" s16 fn_27_DA0F4(OuterObj* self, u32 value, s8 flag) {
    u16 zero = 0;
    return self->m_iface->call(&value, -1, &zero, flag);
}
