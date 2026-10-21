#pragma force_active on
extern "C" unsigned char** g_GameGlobal;

extern "C" void fn_800557C0()
{
    unsigned char* p = *g_GameGlobal;
    p[0x28] &= ~0x10;
}
