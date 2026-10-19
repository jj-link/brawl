#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004E5D8(void*, void*);

extern "C" unsigned short fn_2_255D4(void* arg) {
    return *reinterpret_cast<unsigned short*>(
        static_cast<char*>(fn_8004E5D8(g_GameGlobal, arg)) + 0x62);
}
