#include <types.h>
#pragma force_active on

extern "C" void* getInstance__14gfSceneManagerFv();
extern "C" void fn_8004D010(void* game);
extern void* g_GameGlobal;
extern void* g_gfApplication;

extern "C" void fn_1_34310(char* self) {
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    s32 v = *(s32*)(mgr + 0x31c);
    *(s32*)(self + 0x14) = v;
    if (v == 0xff) {
        *(s32*)(self + 0x8) = 9;
        *(s32*)(self + 0x14) = 0;
    } else {
        *(s32*)(self + 0x8) = 0;
        fn_8004D010(g_GameGlobal);
        char* app = (char*)g_gfApplication;
        self[0x18] = (*(u8*)(app + 0x110)) != 0;
    }
    self[0x19] = 0;
}
