extern unsigned char* g_GameGlobal;

#pragma force_active on
extern "C" int fn_8010EC6C(void) {
    int v = *(int*)(*(unsigned char**)(g_GameGlobal + 0x30) + 0x620) & ~0xFF;
    switch (v) {
    case 0x2A000100:
        return 2;
    case 0x2A000200:
        return 1;
    default:
        return 0;
    }
}
