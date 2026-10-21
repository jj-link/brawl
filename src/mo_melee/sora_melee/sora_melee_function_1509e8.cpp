#include <types.h>
#pragma force_active on

class stSetterObj {
public:
    virtual void v0();
    virtual void* getAt(s32 idx);
};

class stSetter {
public:
    u8 m_pad0[0x148];
    stSetterObj* m_obj;
    void* m_ptr;
    s32 m_cnt1;
    s32 m_cnt2;
    s32 m_idx;
    s32 m_wrap;
};

extern "C" {
void fn_27_1509E8(stSetter* self, s32 idx) {
    if (idx == 0) {
        self->m_ptr = (u8*)self + 0x30;
    } else if (idx > self->m_cnt1) {
        self->m_ptr = (u8*)self + 0xBC;
    } else {
        s32 r = self->m_cnt2 - (idx - 1);
        if (r < 0) {
            r += self->m_wrap;
        }
        self->m_ptr = self->m_obj->getAt(r);
    }
    self->m_idx = idx;
}
}
