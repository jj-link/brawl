#include <types.h>
#pragma force_active on

class ftEntryManager {
public:
    void* getEntity(u32 entryId);
};

struct ftSlotManager {
    u8* m_slots;
};

struct Caller {
    char pad[0x154];
    ftEntryManager* manager;
};

extern ftSlotManager* g_ftSlotManager;
extern "C" void fn_27_120818(void*);

extern "C" void fn_27_109C64(Caller* __restrict self, u32 entryId) {
    void* entity = self->manager->getEntity(entryId);
    u32 index = *reinterpret_cast<u32*>(reinterpret_cast<u8*>(entity) + 0x18);
    fn_27_120818(g_ftSlotManager->m_slots + index * 0x4d4);
}
