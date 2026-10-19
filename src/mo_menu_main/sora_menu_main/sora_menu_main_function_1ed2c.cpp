#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E658(void*);

extern "C" void* fn_2_1ED2C() {
    return *static_cast<void**>(fn_8004E658(g_GameGlobal));
}
