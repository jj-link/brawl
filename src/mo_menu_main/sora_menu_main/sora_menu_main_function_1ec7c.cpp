#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E6C4(void*);

void* fn_2_1EC7C() {
    return *(void**)fn_8004E6C4(g_GameGlobal);
}
}
