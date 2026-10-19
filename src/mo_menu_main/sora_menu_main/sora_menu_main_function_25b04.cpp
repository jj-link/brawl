#pragma force_active on
struct GameGlobal;

extern GameGlobal* g_GameGlobal;
extern "C" void* fn_8004D138(GameGlobal*, void*);

extern "C" void* fn_2_25B04(void* arg) {
    void* result = fn_8004D138(g_GameGlobal, arg);
    return *reinterpret_cast<void**>(
        reinterpret_cast<char*>(result) + 0x50
    );
}
