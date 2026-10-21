#include <types.h>
#pragma force_active on

extern u8 lbl_80487E28[];

struct Local {
    u8* m_0;
    u16 m_4;
    u16 m_6;
    u8 padding[0x108];
};

extern "C" void* fn_802E5608() {
    __declspec(align(16)) Local loc;
    if (&loc != 0) {
        loc.m_6 = 1;
        loc.m_0 = lbl_80487E28;
    }
    return loc.m_0;
}
