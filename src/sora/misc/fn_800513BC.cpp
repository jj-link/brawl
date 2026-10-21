#pragma force_active on
typedef unsigned int u32;
extern "C" void* fn_8004E604(void* object);
extern void* g_GameGlobal;

extern "C" u32 fn_800513BC(void) {
    return *(u32*)fn_8004E604(g_GameGlobal);
}
