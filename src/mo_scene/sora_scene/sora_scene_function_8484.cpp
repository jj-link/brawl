#include <types.h>
#pragma force_active on

extern "C" void* getInstance__14gfSceneManagerFv();

extern "C" s32 fn_1_8484(void* p) {
    char* inner = *(char**)((char*)p + 8);
    if (*(s32*)(inner + 0x44)) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(s32*)(mgr + 0x284) = 0;
        *(s32*)(mgr + 0x288) = 2;
    }
    return 0;
}
