#pragma force_active on
typedef unsigned char u8;

extern "C" void *fn_8004E5C4(void *);
extern "C" void *g_GameGlobal;

extern "C" void fn_800515E8(void) {
    u8 v = *(u8 *)((char *)fn_8004E5C4(g_GameGlobal) + 0x2E4);
    *(u8 *)((char *)((void **)g_GameGlobal)[2] + 0x60) = v;
}
