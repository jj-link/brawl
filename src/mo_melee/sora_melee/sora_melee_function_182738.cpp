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
};

struct fnMid {
    u8 pad[0x40];
    fnInner* inner;
};

struct fnOuter {
    u8 pad[0xd8];
    fnMid* mid;
};

extern "C" {
void fn_27_182738(void*, fnOuter* p) {
    p->mid->inner->v15();
}
}
