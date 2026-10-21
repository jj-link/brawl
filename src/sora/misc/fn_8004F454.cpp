#pragma force_active on
extern "C" {
    extern unsigned char* fn_8004E790(void* p, int v);
    extern void* g_GameGlobal;
}

extern "C" void fn_8004F454(void) {
    *fn_8004E790(g_GameGlobal, 0) = 0xA;
    *fn_8004E790(g_GameGlobal, 1) = 8;
}
