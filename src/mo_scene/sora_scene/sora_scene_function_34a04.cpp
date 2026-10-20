#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
void fn_8004D010(void* game);
extern void* g_GameGlobal;
extern void* g_gfApplication;
}

extern "C" void fn_1_34A04(char* self) {
    unsigned char* mgr = (unsigned char*)getInstance__14gfSceneManagerFv();
    if (*(s32*)(mgr + 0x31c) == 255) {
        *(s32*)(self + 8) = 7;
    } else {
        *(s32*)(self + 8) = 0;
        fn_8004D010(g_GameGlobal);
        unsigned char* app = (unsigned char*)g_gfApplication;
        self[0x11] = (app[0x110] != 0);
    }
    self[0x12] = 0;
}
