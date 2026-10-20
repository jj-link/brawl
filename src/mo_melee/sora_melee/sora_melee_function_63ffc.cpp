#include <types.h>
#pragma force_active on

struct Unk27 {
    u8 pad_00[0x24];
    s32 m_24;
    u8 pad_28[0x3c - 0x28];
    u8 m_3c;
};

extern "C" void fn_27_63FFC(Unk27* p) {
    p->m_24 = -1;
    p->m_3c = 0;
}
