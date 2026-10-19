#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E778(void*);

extern "C" void* fn_2_1EDDC() {
    return *(void**)fn_8004E778(g_GameGlobal);
}
