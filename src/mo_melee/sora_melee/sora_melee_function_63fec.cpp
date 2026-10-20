#include <types.h>
#pragma force_active on

struct soPrefix {
    u32 unk0;
    u32 unk4;
};

class soVirtBase : public soPrefix {
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
};

extern "C" {
void fn_27_63FEC(soVirtBase* p) {
    return p->v7();
}
}
