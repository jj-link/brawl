#include <types.h>
#pragma force_active on

struct UnkStruct {
    u32 m_0;
    s32 m_4;
    u16 m_8;
    s16 m_a;
};

extern "C" {
void fn_27_1BA438(UnkStruct* self) {
    s32 neg = -1;
    self->m_4 = neg;
    self->m_8 = 0;
    self->m_a = neg;
}
}
