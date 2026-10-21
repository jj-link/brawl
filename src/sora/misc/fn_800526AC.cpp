#pragma force_active on
extern unsigned int g_GameGlobal;

extern "C" void fn_800526AC()
{
    char* p = *(char**)g_GameGlobal;
    p[0x28] &= ~0x80;
}
