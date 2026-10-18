#include <types.h>
#pragma force_active on

struct Inner;

struct Outer {
    u8 pad[0x44];
    Inner* m_44;
};

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
    virtual int v16(Outer* o, u32 a);
};

extern "C" int fn_27_2E6C0(Outer* p1, u32 p2) {
    return p1->m_44->v16(p1, p2);
}
