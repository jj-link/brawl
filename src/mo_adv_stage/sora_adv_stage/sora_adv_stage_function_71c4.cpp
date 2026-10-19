#pragma force_active on
extern "C" {
extern unsigned char *g_GameGlobal;

unsigned int fn_40_71C4()
{
    unsigned char *p = *(unsigned char **)((unsigned char *)g_GameGlobal + 0x30);
    unsigned int b = (p[0x4924] >> 6) & 1;
    unsigned int r = (0u - b) | b;
    return r >> 31;
}
}
