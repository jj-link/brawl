#include <types.h>
#include <gf/gf_application.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
void fn_8004D010(void* game);
void* getInstance__14gfSceneManagerFv();
void fn_1_37BDC(void* self);
}

void fn_1_37BDC(void* self) {
    *(s32*)((char*)self + 8) = 0;
    *(u8*)((char*)self + 0x11) = (*(u8*)((char*)g_gfApplication + 0x110) != 0);
    fn_8004D010(g_GameGlobal);
    void* mgr = getInstance__14gfSceneManagerFv();
    s32 state = *(s32*)((char*)mgr + 0x31c);
    switch (state) {
        case 1:
            *(u8*)((char*)g_GameGlobal->m_selCharData + 6) = 1;
            break;
        default:
            break;
    }
}
