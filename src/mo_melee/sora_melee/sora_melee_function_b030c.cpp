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
};

class fnOuter {
public:
    u32 unk0;
    u32 unk4;
    fnInner* m_inner;
};

extern "C" {
void fn_27_B030C(fnOuter* self) {
    self->m_inner->v4();
}
}
