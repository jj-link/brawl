#include <types.h>
#pragma force_active on

class fnInner {
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
    virtual s32 call(u32* p0, s32 p1, u16* p2, s8 p3);
};

class fnOuter {
public:
    u8 m_pad[8];
    fnInner* m_inner;
};

extern "C" s16 fn_27_11B7C8(fnOuter* self, u32 val, s8 flag) {
    u16 r = 0;
    return (s16)self->m_inner->call(&val, -1, &r, flag);
}
