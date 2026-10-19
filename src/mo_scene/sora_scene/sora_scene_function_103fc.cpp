#pragma force_active on
extern "C" void* getInstance__14gfSceneManagerFv();
extern "C" void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern char* g_gfApplication;

extern "C" int fn_1_103FC(char* self) {
    char* scene = *(char**)(self + 8);
    if (scene != 0 && *(unsigned int*)(scene + 0x40) != 0) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(unsigned int*)(mgr + 0x284) = 0;
        *(unsigned int*)(mgr + 0x288) = 2;
        startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
    }
    return 0;
}
