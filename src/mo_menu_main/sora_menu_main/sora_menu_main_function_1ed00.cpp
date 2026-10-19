#pragma force_active on
extern "C" {
struct GameGlobal;
extern GameGlobal* g_GameGlobal;
void* fn_8004E64C(GameGlobal*);

void* fn_2_1ED00() {
    return *(void**)fn_8004E64C(g_GameGlobal);
}
}
