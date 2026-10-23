#include <types.h>
#pragma force_active on

extern u8 lbl_804877E8[];

struct Local {
    void* m_ptr;
    s16 m_unused;
    s16 m_flag;
    u8 m_padding[8];
};

extern "C" void* fn_802D5DBC() {
    __declspec(align(16)) Local loc;
    if (&loc != 0) {
        loc.m_flag = 1;
        loc.m_ptr = lbl_804877E8;
    }
    return loc.m_ptr;
}
