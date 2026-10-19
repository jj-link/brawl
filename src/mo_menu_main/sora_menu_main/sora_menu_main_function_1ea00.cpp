#pragma force_active on
typedef unsigned int u32;

struct GameGlobal;

extern "C" {
extern GameGlobal* g_GameGlobal;
u32* fn_8004E6E8(GameGlobal*);

u32 fn_2_1EA00() {
    return *fn_8004E6E8(g_GameGlobal);
}
}
