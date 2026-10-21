#pragma force_active on
extern void* g_efScreen;
extern "C" void __dl__FPv(void*);

extern "C" void fn_8005D5A8(void) {
    void* p = g_efScreen;
    if (p == 0) {
        return;
    }
    if (p == 0) {
        return;
    }
    g_efScreen = 0;
    __dl__FPv(p);
}
