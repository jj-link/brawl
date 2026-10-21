#pragma force_active on
typedef unsigned char u8;

extern "C" void *fn_8004E5C4(void *);
extern void *g_GameGlobal;

extern "C" void fn_80051680(void) {
    u8 v = ((u8 *)fn_8004E5C4(g_GameGlobal))[0x2E5];
    ((u8 *)(*(u8 **)((u8 *)g_GameGlobal + 0x8)))[0x61] = v;
}
