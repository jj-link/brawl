#include <types.h>
#pragma force_active on

class Inner {
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
    virtual s32 target(s32* ptr, s32 idx, u16* out, s8 flag);
};

class Outer {
public:
    u32 m_pad0;
    u32 m_pad4;
    Inner* m_inner;
};

struct Local {
    s32 v;
    u16 out;
};

extern "C" s16 fn_27_DA554(Outer* self, s32 value, s8 flag) {
    Local l;
    l.v = value;
    l.out = 0;
    s32 r = self->m_inner->target(&l.v, -1, &l.out, flag);
    return (s16)r;
}
