#include <em/em_manager.h>
#pragma force_active on

namespace {
    struct EntryRaw {
        u8 m_flags[4];
        s32 m_kind;
        s32 m_parentCreateId;
        s32 m_createId;
        s32 m_soundGroupOffset;
        Enemy* m_dataPtr;
    };
}

extern "C" void* fn_41_CD80(emManager*, int);

Enemy* emManager::getEnemyPtrFromId(int createId) {
    EntryRaw* entry = (EntryRaw*)fn_41_CD80(this, createId);
    if (entry == nullptr) {
        return nullptr;
    }
    if (entry->m_flags[0] == 0) {
        return nullptr;
    }
    return entry->m_dataPtr;
}
