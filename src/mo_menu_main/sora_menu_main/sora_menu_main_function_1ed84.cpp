#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E694(void*);

extern "C" void* fn_2_1ED84() {
    return *static_cast<void**>(fn_8004E694(g_GameGlobal));
}
