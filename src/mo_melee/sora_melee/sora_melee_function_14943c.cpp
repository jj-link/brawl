#include <types.h>
#pragma force_active on

struct Sub {
    u8 pad[0xBC];
    s32 m_bc;
};

struct Outer {
    u8 pad[0x24];
    Sub* m_24;
};

extern "C" Outer lbl_27_bss_3210;

extern "C" s32 fn_27_14943C() {
    return lbl_27_bss_3210.m_24->m_bc;
}
