#pragma force_active on
extern "C" void *fn_8004E5C4(void *);
extern void *g_GameGlobal;

extern "C" unsigned char fn_800515C0(void) {
    return *(unsigned char *)((char *)fn_8004E5C4(g_GameGlobal) + 0x2E4);
}
