#include <types.h>
#pragma force_active on

class soInnerWork {
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
};

class soOuterWork {
public:
    u8 m_pad[0x54];
    soInnerWork* m_inner;
};

extern "C" {
void fn_27_2480AC(soOuterWork* self) {
    if (self->m_inner) {
        self->m_inner->v6();
    }
}
}
