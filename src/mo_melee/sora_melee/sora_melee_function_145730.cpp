#pragma force_active on
extern "C" void fn_27_12006C(char*, int);

struct ftSlotManager {
    char* m_slots;
};

extern ftSlotManager* g_ftSlotManager;

extern "C" void fn_27_145730(int unused, int idx)
{
    fn_27_12006C(g_ftSlotManager->m_slots + idx * 0x4d4, 8);
}
