#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void target(s16 x);
};

class soOuter {
public:
    u32 unk0;
    u32 unk4;
    soInner* m_8;
};

extern "C" void fn_27_51074(soOuter* self, s16 x) {
    self->m_8->target(x);
}
