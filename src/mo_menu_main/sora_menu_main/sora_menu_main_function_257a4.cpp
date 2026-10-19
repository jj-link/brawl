#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void* fn_8004D138(void*, void*);

extern "C" void* fn_2_257A4(void* arg) {
    void* result = fn_8004D138(g_GameGlobal, arg);
    return *reinterpret_cast<void**>(
        reinterpret_cast<unsigned char*>(result) + 0x2C
    );
}
