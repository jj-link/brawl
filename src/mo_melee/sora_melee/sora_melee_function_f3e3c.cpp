#include <types.h>
#pragma force_active on

struct Node {
    s32 m_head;
    s32 m_value;
};

struct Inner {
    virtual void vf0();
    virtual Node* vf1();
    virtual void vf2();
};

struct Outer {
    s32 m_pad[4];
    Inner m_inner;
};

extern "C" s32 fn_27_F3E3C(Outer* self) {
    return self->m_inner.vf1()->m_value;
}
