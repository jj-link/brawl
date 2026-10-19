#include <types.h>
#pragma force_active on

extern "C" s32 fn_800EE5EC(void* p);
extern "C" void* getInstance__14gfSceneManagerFv();
extern "C" void startKeepScreen__17gfKeepFrameBufferFv(void* self);
extern char* g_gfApplication;

extern "C" s32 fn_1_1B0B4(char* p) {
    if (fn_800EE5EC(*(void**)(p + 8))) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(s32*)(mgr + 0x284) = 0;
        *(s32*)(mgr + 0x288) = 2;
        startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
    }
    return 0;
}
