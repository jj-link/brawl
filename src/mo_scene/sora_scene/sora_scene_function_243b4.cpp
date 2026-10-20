#include <gf/gf_application.h>
#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_8004D010(void* game);
extern u8 lbl_1_bss_18C0;
}

extern "C" void fn_1_243B4(void* self) {
    *(u32*)((char*)self + 8) = 0;
    *(u8*)((char*)self + 0x18) = *(u8*)((char*)g_gfApplication + 0x110) != 0;
    fn_8004D010(g_GameGlobal);
    lbl_1_bss_18C0 = g_GameGlobal->m_setRule->m_handicap;
    g_GameGlobal->m_setRule->m_handicap = 0;
}
