#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E6DC(void*);
}

extern "C" void* fn_2_1E9D4() {
    return *static_cast<void**>(fn_8004E6DC(g_GameGlobal));
}
