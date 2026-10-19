#pragma force_active on
extern "C" {
    int fn_27_23AC10();
    void fn_27_10A128(void* owner, unsigned long entityId, unsigned long id);
}
extern void* g_ftManager;

extern "C" void fn_27_23E614(void* owner) {
    if (fn_27_23AC10()) {
        fn_27_10A128(g_ftManager, *(unsigned long*)((char*)owner + 0x4c), 0);
    }
}
