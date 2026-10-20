#include <types.h>
#pragma force_active on

class OwnerObj;

class SubObj {
public:
    virtual void vf0();
    virtual OwnerObj* getTarget(u32 v);
};

class OwnerObj {
public:
    char pad0[0x48];
    SubObj* m_sub;
    char pad1[0x9c - 0x4c];
    float m_floatVal;
    char pad2[0xb1 - 0xa0];
    u8 m_byteVal;
};

extern "C" {
void fn_27_49518(OwnerObj* self, u8 a, u32 b, float c) {
    OwnerObj* t = self->m_sub->getTarget(b);
    t->m_byteVal = a;
    t->m_floatVal = c;
}
}
