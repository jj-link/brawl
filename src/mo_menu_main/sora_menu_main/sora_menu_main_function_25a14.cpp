#pragma force_active on
extern "C" void* fn_8004E5D8(void*, void*);
extern void* g_GameGlobal;

extern "C" void* fn_2_25A14(void* arg) {
    void* p = fn_8004E5D8(g_GameGlobal, arg);
    return *reinterpret_cast<void**>(static_cast<char*>(p) + 0x8C);
}
