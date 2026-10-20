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
};

class fnOuter {
public:
    u8 pad[0x28];
    fnInner* m_inner;
};

extern "C" {
void fn_27_B58E4(fnOuter* self) {
    self->m_inner->v7();
}
}
