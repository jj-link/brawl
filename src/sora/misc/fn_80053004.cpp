#pragma force_active on
typedef unsigned char u8;

extern void* g_GameGlobal;

extern "C" void fn_80053004(void)
{
    u8* g = (u8*)g_GameGlobal;
    u8* s = *(u8**)(g + 0x48);
    u8* d = *(u8**)(g + 0x1c);
    d[2] = s[0];
    d[3] = s[1];
    d[4] = s[2];
    d[5] = s[3];
    d[6] = s[4];
    d[7] = s[5];
    g = (u8*)g_GameGlobal;
    s = *(u8**)(g + 0x4c);
    d = *(u8**)(g + 0x1c);
    d[8] = s[0];
    d[9] = s[1];
    d[10] = s[2];
    d[11] = s[3];
    d[12] = s[4];
}
