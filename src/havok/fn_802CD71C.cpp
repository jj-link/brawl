#include <types.h>
#pragma force_active on
extern u8 lbl_80487320[];
struct Local {
    void* m_ptr;
    s16 m_unused;
    s16 m_flag;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
};
extern "C" void* fn_802CD71C() {
    __declspec(align(16)) Local loc;
    if (&loc != 0) {
        loc.m_flag = 1;
        loc.m_ptr = lbl_80487320;
        loc.m_08 = lbl_80487320 + 0x10;
        loc.m_0c = lbl_80487320 + 0x20;
        loc.m_10 = lbl_80487320 + 0x30;
        loc.m_14 = lbl_80487320 + 0x40;
    }
    return loc.m_ptr;
}