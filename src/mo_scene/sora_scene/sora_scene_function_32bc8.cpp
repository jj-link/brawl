#pragma force_active on
extern "C" {
void* getInstance__14gfSceneManagerFv();
void fn_8004D010(void* game);
extern void* g_GameGlobal;
extern void* g_gfApplication;

void fn_1_32BC8(int* self) {
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    if (*(int*)(mgr + 0x31c) == 0xff) {
        self[2] = 0xa;
    } else {
        self[2] = 0;
        fn_8004D010(g_GameGlobal);
        unsigned char c = *(unsigned char*)((char*)g_gfApplication + 0x110);
        *(unsigned char*)((char*)self + 0x18) = (c != 0);
    }
}
}
