#include <types.h>
#pragma force_active on

extern "C" void fn_8027CD94(void* a, s32 b, s32 c);

struct Fn802DBA6C_Class {
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;
};

extern "C" void fn_802DBA6C(Fn802DBA6C_Class* self, s32 arg1) {
    s32 val = self->m_unk8 & 0x3FFFFFFF;
    if (val < arg1) {
        s32 doubled = val * 2;
        fn_8027CD94(self, (arg1 < doubled) ? doubled : arg1, 0x4C);
    }
    self->m_unk4 = arg1;
}