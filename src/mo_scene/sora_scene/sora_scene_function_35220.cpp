#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
void fn_8004D010(void* game);
extern void* g_GameGlobal;
extern void* g_gfApplication;
extern char lbl_1_bss_1B68;
}

extern "C" void fn_1_35220(char* self) {
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    *(int*)(self + 0x14) = *(int*)(mgr + 0x31c);
    lbl_1_bss_1B68 = 0;
    if (*(int*)(self + 0x14) == 0xff) {
        *(int*)(self + 8) = 0xa;
    } else {
        *(int*)(self + 8) = 0;
        *(unsigned char*)(self + 0x11) = (*(unsigned char*)((char*)g_gfApplication + 0x110) != 0);
        fn_8004D010(g_GameGlobal);
        int val = *(int*)(self + 0x14);
        char* ptr = (char*)(*(void**)((char*)g_GameGlobal + 0x10));
        switch (val) {
            default: ptr[2] = 0; break;
            case 1: ptr[2] = 1; break;
            case 2: ptr[2] = 2; break;
            case 3: ptr[2] = 3; break;
            case 4: ptr[2] = 4; break;
            case 5: ptr[2] = 5; break;
        }
    }
    *(unsigned char*)(self + 0x18) = 0;
}