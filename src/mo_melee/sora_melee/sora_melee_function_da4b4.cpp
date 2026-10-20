#include <types.h>
#pragma force_active on

struct IInner {
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
    virtual s32 v18(u32* p1, s32 p2, u16* p3, s8 p4);
};

struct IOuter {
    u8 pad[8];
    IInner* m_inner;
};

struct Locals {
    u32 a;
    u16 b;
};

extern "C" s16 fn_27_DA4B4(IOuter* self, u32 a, s8 b) {
    Locals l;
    l.a = a;
    l.b = 0;
    return self->m_inner->v18(&l.a, -1, &l.b, b);
}
