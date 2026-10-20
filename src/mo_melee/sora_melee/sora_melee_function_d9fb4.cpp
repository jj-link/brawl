#include <types.h>
#pragma force_active on

class soInnerBase {
public:
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
    virtual s32 callFn(u32* val, s32 idx, s16* out, s8 flag);
};

class soOuter {
public:
    u8 pad[8];
    soInnerBase* m_inner;
};

extern "C" {
s16 fn_27_D9FB4(soOuter* self, u32 val, s8 flag) {
    s16 out = 0;
    return self->m_inner->callFn(&val, -1, &out, flag);
}
}
