#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E61C(void*);

extern "C" void* fn_2_1ED58() {
    return *static_cast<void**>(fn_8004E61C(g_GameGlobal));
}
