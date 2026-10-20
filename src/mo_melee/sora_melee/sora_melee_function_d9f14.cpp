#include <types.h>
#pragma force_active on

struct Inner {
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
    virtual s32 vf(u32* a, s32 b, s16* c, s8 d);
};

struct Outer {
    u32 unk0;
    u32 unk4;
    Inner* inner;
};

struct Locals {
    u32 a;
    s16 c;
};

extern "C" {
s16 fn_27_D9F14(Outer* o, u32 a, s8 d) {
    Locals l;
    l.a = a;
    l.c = 0;
    return o->inner->vf(&l.a, -1, &l.c, d);
}
}
