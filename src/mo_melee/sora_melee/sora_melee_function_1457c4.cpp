#pragma force_active on
struct ftSlotManager {
    char* m_slots;
};

extern ftSlotManager* g_ftSlotManager;
extern "C" void fn_27_12006C(char*, int, int, int);

extern "C" void fn_27_1457C4(int unused, int idx, int code)
{
    char* p;

    if (code == 0x31) {
        p = g_ftSlotManager->m_slots + idx * 0x4d4;
        fn_27_12006C(p, 7, 0x15, 0);
    } else if (code == 0x30) {
        p = g_ftSlotManager->m_slots + idx * 0x4d4;
        fn_27_12006C(p, 7, 0x0b, 0);
    } else {
        p = g_ftSlotManager->m_slots + idx * 0x4d4;
        fn_27_12006C(p, 7, code, 0);
    }
}
