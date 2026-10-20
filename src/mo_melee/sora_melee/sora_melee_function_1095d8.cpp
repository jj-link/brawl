#pragma force_active on
struct ftSlotManagerObj {
    char* entries;
};

extern "C" {
    extern ftSlotManagerObj* g_ftSlotManager;
    void* fn_27_11E6AC(void* p, int arg);
    void* fn_27_1095D8(int unused, int slot, int arg)
    {
        return fn_27_11E6AC(g_ftSlotManager->entries + slot * 0x4d4, arg);
    }
}
