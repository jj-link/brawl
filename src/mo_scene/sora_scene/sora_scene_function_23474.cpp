#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
void* searchScene__14gfSceneManagerFPCc(void* mgr, const char* name);
void fn_8004D010(void* game);
void fn_80050160(void* p);
extern char lbl_1_data_7070[];
extern void* lbl_1_bss_18B8;
extern void* g_GameGlobal;

void fn_1_23474(void* self) {
    s32 state = *(s32*)((char*)getInstance__14gfSceneManagerFv() + 0x31c);
    if (state == 0xff) {
        *(s32*)((char*)self + 8) = 0xf;
        return;
    }
    *(s32*)((char*)self + 8) = 0;
    *(u8*)((char*)self + 0x11) = 0;
    lbl_1_bss_18B8 = searchScene__14gfSceneManagerFPCc(getInstance__14gfSceneManagerFv(), lbl_1_data_7070);
    fn_8004D010(g_GameGlobal);
    fn_80050160(((void**)g_GameGlobal)[2]);
}
}
