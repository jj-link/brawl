#pragma force_active on
extern "C" void fn_8004D010(void* game);
extern "C" void* getInstance__14gfSceneManagerFv();
extern void* g_GameGlobal;

extern "C" void fn_1_35F64(void* self) {
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    if (*(int*)(mgr + 0x31c) == 0xff) {
        *(int*)((char*)self + 8) = 10;
    } else {
        *(int*)((char*)self + 8) = 0;
        fn_8004D010(g_GameGlobal);
    }
}
