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
extern "C" void fn_27_11FC6C(void*, u32, s32);

extern "C" void fn_27_109C10(Caller* __restrict self, u32 entryId, u32 value) {
    void* entity = self->manager->getEntity(entryId);
    u32 index = *reinterpret_cast<u32*>(reinterpret_cast<u8*>(entity) + 0x18);
    fn_27_11FC6C(g_ftSlotManager->m_slots + index * 0x4d4, value, -1);
}
