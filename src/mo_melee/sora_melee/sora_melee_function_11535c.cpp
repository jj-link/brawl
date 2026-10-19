#pragma force_active on
extern void *g_GameGlobal;

extern "C" {
unsigned char fn_27_11535C(char *p)
{
    int idx = *(int *)(p + 0x58);
    char *g = (char *)g_GameGlobal;
    char *a = *(char **)(g + 0x8);
    char *b = *(char **)(g + 0x18);
    unsigned char sub = *(unsigned char *)(a + idx * 0x5c + 0x9b);
    return *(unsigned char *)(b + sub * 0x2ac + 0x32);
}
}
