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
    virtual s32 v13(s32 a, s32 b, s32 c);
    virtual void v14();
    virtual void v15();
};

struct Mid {
    char pad[0x24];
    Inner* inner;
};

struct Outer {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
s32 fn_27_16A788(s32 unused, Outer* p) {
    return p->mid->inner->v13(0, 0, 0);
}
}
