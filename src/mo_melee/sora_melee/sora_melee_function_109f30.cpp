#include <types.h>
#pragma force_active on

class ftEntry;

class ftEntryManager {
public:
    ftEntry* getEntity(u32 id);
};

extern "C" void fn_27_1140B0(ftEntry* entry, u32 arg);

extern "C" {
void fn_27_109F30(void* self, u32 id, u32 arg) {
    ftEntryManager* mgr = *(ftEntryManager**)((char*)self + 0x154);
    ftEntry* entry = mgr->getEntity(id);
    fn_27_1140B0(entry, arg);
}
}
