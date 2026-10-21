#include <types.h>
#pragma force_active on

extern u8 lbl_80487380[];

struct Local {
    void* m_ptr;
    s16 m_unused;
    s16 m_flag;
    u8 m_padding[16];
};

extern "C" void* fn_802CD914() {
    __declspec(align(16)) Local loc;
    if (&loc != 0) {
        loc.m_flag = 1;
        loc.m_ptr = lbl_80487380;
    }
    return loc.m_ptr;
}
