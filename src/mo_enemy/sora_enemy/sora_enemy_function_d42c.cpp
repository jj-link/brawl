#include <em/em_manager.h>
#pragma force_active on

extern "C" void* fn_41_D5A0(emManager* self, u32 idx);
extern "C" int fn_41_D380(emManager* self, u32 param);

bool emManager::isCompArchiveAll() {
    for (u32 i = 0; i < m_numArchiveEntries; i++) {
        u8* e = (u8*)fn_41_D5A0(this, i);
        if (e != 0 && e[0] != 0) {
            if (fn_41_D380(this, *(u32*)(e + 0x0C)) == 0) {
                return false;
            }
        }
    }
    return true;
}
