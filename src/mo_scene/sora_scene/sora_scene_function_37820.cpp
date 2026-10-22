#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
extern void* g_gfApplication;
}

extern "C" void fn_1_37820(char* self) {
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    int idx = *(int*)(mgr + 0x31c);
    *(int*)(self + 0x14) = idx;
    *(int*)(self + 8) = 0;
    unsigned char c = *(unsigned char*)((char*)g_gfApplication + 0x110);
    *(char*)(self + 0xc) = (c != 0);
    switch (idx) {
    case 24:
    default:
        *(int*)(self + 0x10) = 0;
        break;
    case 25:
        *(int*)(self + 0x10) = 1;
        break;
    case 26:
        *(int*)(self + 0x10) = 2;
        break;
    case 27:
        *(int*)(self + 0x10) = 3;
        break;
    }
}
