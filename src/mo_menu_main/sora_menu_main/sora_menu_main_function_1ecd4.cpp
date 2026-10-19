#pragma force_active on
extern "C" {
struct GameGlobal;
extern GameGlobal* g_GameGlobal;
void* fn_8004E640(GameGlobal*);

void* fn_2_1ECD4() {
    return *(void**)fn_8004E640(g_GameGlobal);
}
}
