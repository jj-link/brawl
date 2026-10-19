#pragma force_active on
struct GameGlobalSub { char pad[4]; unsigned char m_val; };
struct GameGlobal { char pad[0x10]; GameGlobalSub* m_sub; };
extern GameGlobal* g_GameGlobal;

extern "C" unsigned char fn_10_1264() {
    return g_GameGlobal->m_sub->m_val;
}
