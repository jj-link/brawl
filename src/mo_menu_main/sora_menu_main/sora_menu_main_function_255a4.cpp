#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
extern void* fn_8004D138(void*, void*);

unsigned short fn_2_255A4(void* arg) {
    void* result = fn_8004D138(g_GameGlobal, arg);
    return *(unsigned short*)((char*)result + 0x1C);
}
}
