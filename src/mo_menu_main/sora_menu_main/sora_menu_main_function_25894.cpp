#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E5D8(void*, void*);

extern "C" void* fn_2_25894(void* arg) {
    return *reinterpret_cast<void**>(
        static_cast<char*>(fn_8004E5D8(g_GameGlobal, arg)) + 0x7C);
}
