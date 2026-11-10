#include <types.h>
#pragma force_active on

class Heap {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2(u32 size, s32 arg, s32 align);
};

class Owner {
public:
    void* m_00;
    s32 m_04;
    s32 m_08;
    s32 m_0c;
    s32 m_10;
    s32 m_14;
};

extern Heap* lbl_805A0EB8;

extern "C" Owner* fn_80280CEC(Owner* self, s32 arg) {
    self->m_00 = lbl_805A0EB8->slot2(0x40, arg, 0x18);
    self->m_04 = 0;
    self->m_08 = 0;
    self->m_0c = arg;
    self->m_10 = -1;
    self->m_14 = -1;
    return self;
}
