#pragma force_active on
extern "C" void* fn_8004E5D8(void*, void*);
struct GameGlobal;
extern GameGlobal* g_GameGlobal;

extern "C" void* fn_2_1E808(void* arg) {
    return *reinterpret_cast<void**>(
        static_cast<char*>(fn_8004E5D8(g_GameGlobal, arg)) + 0x68
    );
}
