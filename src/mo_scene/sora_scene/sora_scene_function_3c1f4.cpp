#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_gfApplication;
extern void* g_GameGlobal;
extern char lbl_1_data_99BC[];
extern void* lbl_1_bss_1B90;
extern u32 lbl_1_bss_1B94;

void fn_8004D010(void* game);
void* getInstance__14gfSceneManagerFv();
void* searchScene__14gfSceneManagerFPCc(void* mgr, const char* name);

void fn_1_3C1F4(void* self) {
    ((u32*)self)[2] = 0;
    ((u32*)self)[3] = 0;
    ((u8*)self)[0x10] = *(u8*)((char*)g_gfApplication + 0x110) != 0;
    fn_8004D010(g_GameGlobal);
    lbl_1_bss_1B90 =
        searchScene__14gfSceneManagerFPCc(getInstance__14gfSceneManagerFv(), lbl_1_data_99BC);
    lbl_1_bss_1B94 = 0;
}
}
