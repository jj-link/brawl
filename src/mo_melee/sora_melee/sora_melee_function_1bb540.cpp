#include <types.h>
#pragma force_active on

class Node {
public:
    void* m_pad;
    void* m_val;
};

class Inner {
public:
    virtual void vf0();
    virtual Node* vf1();
    virtual void vf2();
    virtual void vf3();
};

class Outer {
public:
    u8 pad[0x10];
    Inner m_inner;
    void* m_ptr;
};

extern "C" {
void* fn_27_1BB540(Outer* self) {
    return self->m_inner.vf1()->m_val;
}
}
