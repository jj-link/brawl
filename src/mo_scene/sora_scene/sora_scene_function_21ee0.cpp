#pragma force_active on
extern "C" void* getInstance__14gfSceneManagerFv();
extern "C" char* g_gfApplication;

extern "C" void fn_1_21EE0(char* self) {
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    *(int*)(self + 0x14) = *(int*)(mgr + 0x31c);
    if ((*(int*)(g_gfApplication + 0xe4) >> 24) == 1) {
        *(int*)(self + 0x14) = 2;
    }
    *(int*)(self + 0x8) = 0;
}
