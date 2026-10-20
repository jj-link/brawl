#include <types.h>
#pragma force_active on

struct ftSlotManager {
    u8* m_slots;
};

extern ftSlotManager* g_ftSlotManager;
extern "C" void fn_27_12006C(char*, int, int, int);

extern "C" void fn_27_14574C(void* p, int idx, int code) {
    if (code == 0x31) {
        fn_27_12006C((char*)g_ftSlotManager->m_slots + idx * 0x4d4, 5, 0x15, 0);
    } else if (code == 0x30) {
        fn_27_12006C((char*)g_ftSlotManager->m_slots + idx * 0x4d4, 5, 0x0b, 0);
    } else {
        fn_27_12006C((char*)g_ftSlotManager->m_slots + idx * 0x4d4, 5, code, 0);
    }
}
