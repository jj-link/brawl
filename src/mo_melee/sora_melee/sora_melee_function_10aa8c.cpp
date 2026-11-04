#include <types.h>
#pragma force_active on

class ftEntry;

class ftEntryManager {
public:
    ftEntry* getEntity(u32 id);
};

struct Caller {
    char pad[0x154];
    ftEntryManager* manager;
};

extern "C" void fn_27_1141C4(ftEntry*, u32);

extern "C" void fn_27_10AA8C(Caller* __restrict self, u32 entryId, u32 value) {
    ftEntry* ent = self->manager->getEntity(entryId);
    fn_27_1141C4(ent, value);
}
