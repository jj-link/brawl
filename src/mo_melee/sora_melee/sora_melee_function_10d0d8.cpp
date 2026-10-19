#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32);
extern "C" void fn_27_116C5C(ftEntry*, f32);

class ftManager {
public:
    void setHeal(int, f32 heal);
    u8 unk0[0x154];
    u32 m_entityId;
};

void ftManager::setHeal(int, f32 heal) {
    ftEntry* entry = getEntity__14ftEntryManagerFUl(m_entityId);
    fn_27_116C5C(entry, heal);
}
