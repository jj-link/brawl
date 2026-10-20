#include <em/em_manager.h>
#include <types.h>
#pragma force_active on

extern "C" s32* fn_41_CD5C(s32* obj, s32 index);
extern "C" void fn_41_CBD4(emManager* mgr, u32 param2);

void emManager::removeEnemyAll() {
    for (unsigned int i = 0; i < m_numEnemyEntries; i++) {
        s32* entry = fn_41_CD5C((s32*)this, (s32)i);
        if (entry && *(unsigned char*)entry == 1) {
            fn_41_CBD4(this, (u32)entry[3]);
        }
    }
}
