#pragma force_active on
extern "C" void* fn_8004D138(void*, void*);

extern void* g_GameGlobal;

extern "C" unsigned short fn_2_25664(void* arg) {
    void* result = fn_8004D138(g_GameGlobal, arg);
    return *(unsigned short*)((char*)result + 0x20);
}
