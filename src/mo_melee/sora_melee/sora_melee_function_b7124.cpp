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
    virtual void v8(s32 a, s32 b, s32 c);
};

class soOuter {
public:
    u8 pad[0x1c];
    s32 m_1c;
    u8 pad2[0x2c - 0x20];
    soInner* m_2c;
};

extern "C" {
void fn_27_B7124(soOuter* self, s32 a, s32 b) {
    self->m_2c->v8(a, b, self->m_1c);
}
}
