#include <types.h>
#pragma force_active on

struct fn_27_60A44_Obj {
    u8 m_00;
    s32 m_04;
    s32 m_08;
    s32 m_0c;
    u8 m_10;
    s32 m_14;
    s32 m_18;
    s32 m_1c;
    s32 m_20;
    s32 m_24;
};

extern "C" {
void fn_27_60A44(fn_27_60A44_Obj* self) {
    if (self->m_24 <= 0) {
        return;
    }
    self->m_24--;
    if (self->m_24 != 0) {
        return;
    }
    self->m_04 = -1;
    self->m_00 = 0;
    self->m_08 = -1;
    self->m_0c = -1;
    self->m_14 = -1;
    self->m_18 = -1;
    self->m_10 = 0;
    self->m_1c = -1;
    self->m_20 = -1;
    self->m_24 = -1;
}
}
