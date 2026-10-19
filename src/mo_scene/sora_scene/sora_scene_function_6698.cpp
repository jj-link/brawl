#include <types.h>
#pragma force_active on

extern "C" {
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void* pad, int port, void* status);
void fn_800288A4(void* status);
void* getInstance__14gfSceneManagerFv();
int fn_1_6698(char* self);
}

extern void* g_gfPadSystem;

int fn_1_6698(char* self) {
    u8 status[0x40];
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xf0, status);
    fn_800288A4(status);
    char* obj = *(char**)(self + 0xc);
    if (*(s32*)(obj + 0x40) == 8) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(s32*)(mgr + 0x284) = 0;
        *(s32*)(mgr + 0x288) = 2;
    }
    return 0;
}
