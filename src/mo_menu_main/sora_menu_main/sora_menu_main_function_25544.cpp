#pragma force_active on
struct GameGlobal;

extern "C" GameGlobal* g_GameGlobal;
extern "C" void* fn_8004D138(GameGlobal*, void*);

extern "C" void* fn_2_25544(void* arg) {
    void* result = fn_8004D138(g_GameGlobal, arg);
    return *(void**)((char*)result + 0x18);
}
