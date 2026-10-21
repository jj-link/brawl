#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void *fn_8004E5C4(void *);
extern "C" void *g_GameGlobal;

extern "C" void fn_8005161C(u32 arg0) {
    u8 *p = (u8 *)fn_8004E5C4(g_GameGlobal);
    p[0x2E4] = (u8)(p[0x2E4] | arg0);
}
