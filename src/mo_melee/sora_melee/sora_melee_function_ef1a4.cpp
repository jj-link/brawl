#include <types.h>
#pragma force_active on

struct fn_27_EF1A4_obj {
    u8 pad0[4];
    s32 m_unk4;
    s16 m_unk8;
    s16 m_unkA;
};

extern "C" void fn_27_EF1A4(fn_27_EF1A4_obj* obj) {
    obj->m_unk4 = -1;
    obj->m_unk8 = 0;
    obj->m_unkA = -1;
}
