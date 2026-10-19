#pragma force_active on
extern "C" {
extern void* g_GameGlobal;

unsigned char fn_88_3BDC()
{
    char* gg = (char*)g_GameGlobal;
    char* p = *(char**)(gg + 0x8);
    if (p == 0) {
        return 0;
    }
    return *(unsigned char*)(p + 0x64);
}
}
