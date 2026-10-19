#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E5D8(void*, void*);

extern "C" void* fn_2_25774(void* arg) {
    void* result = fn_8004E5D8(g_GameGlobal, arg);
    return *reinterpret_cast<void**>(reinterpret_cast<char*>(result) + 0x70);
}
