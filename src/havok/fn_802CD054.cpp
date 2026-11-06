#include <types.h>
#pragma force_active on
extern u8 lbl_804872B8[];
struct Local {
    void* m_ptr;
    s16 m_unused;
    s16 m_flag;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    u8 padding[0x88];
};
extern "C" void* fn_802CD054() {
    __declspec(align(16)) Local loc;
    if (&loc != 0) {
        loc.m_flag = 1;
        loc.m_ptr = lbl_804872B8;
        loc.m_08 = lbl_804872B8 + 0x10;
        loc.m_0c = lbl_804872B8 + 0x20;
        loc.m_10 = lbl_804872B8 + 0x30;
        loc.m_14 = lbl_804872B8 + 0x40;
    }
    return loc.m_ptr;
}