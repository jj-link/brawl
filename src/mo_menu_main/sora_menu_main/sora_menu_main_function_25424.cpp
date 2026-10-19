#pragma force_active on
extern "C" void* fn_8004D138(void*, void*);
extern void* g_GameGlobal;

extern "C" unsigned short fn_2_25424(void* arg) {
    return *reinterpret_cast<unsigned short*>(
        static_cast<char*>(fn_8004D138(g_GameGlobal, arg)) + 2);
}
