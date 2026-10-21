#pragma force_active on
typedef unsigned int u32;
extern "C" void* fn_8004E604(void* object);
extern "C" void* fn_8004E610(void* ptr);
extern void* g_GameGlobal;

extern "C" u32 fn_800513E4(u32 arg0) {
    u32* p1 = (u32*)fn_8004E604(g_GameGlobal);
    u32* p2 = (u32*)fn_8004E610(g_GameGlobal);
    if (arg0 > *p2) {
        *p2 = arg0;
    }
    *p1 = arg0;
    return arg0;
}
