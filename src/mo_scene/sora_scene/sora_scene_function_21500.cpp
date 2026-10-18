#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
void* searchScene__14gfSceneManagerFPCc(void* mgr, const char* name);
void fn_8004D010(void* game);
void fn_80050160(void* p);
extern char lbl_1_data_6BA0[];
extern void* lbl_1_bss_1798;
extern void* g_GameGlobal;

void fn_1_21500(s32* self) {
    s32 state = *(s32*)((char*)getInstance__14gfSceneManagerFv() + 0x31c);
    lbl_1_bss_1798 = searchScene__14gfSceneManagerFPCc(getInstance__14gfSceneManagerFv(), lbl_1_data_6BA0);
    switch (state) {
        case 0:
            self[2] = 0;
            self[3] = 0;
            fn_8004D010(g_GameGlobal);
            fn_80050160(((void**)g_GameGlobal)[2]);
            break;
        case 0xff:
            self[2] = 0xf;
            self[3] = 0xf;
            break;
    }
}
}
