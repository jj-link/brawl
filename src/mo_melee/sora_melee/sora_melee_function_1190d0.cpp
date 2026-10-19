#include <types.h>
#pragma force_active on

struct UnkEntry {
    s32 m_pad0;
    s32 m_id;
    u8 m_rest[0x244 - 8];
};

struct UnkList {
    UnkEntry* m_entries;
    s32 m_count;
};

extern "C" {
bool fn_27_1190D0(UnkList* list, s32 id) {
    if (id != -1) {
        u8 idx = (u8)id;
        if ((s32)idx < list->m_count) {
            UnkEntry* entry = (UnkEntry*)((u8*)list->m_entries + idx * 0x244);
            if (id == entry->m_id) {
                return true;
            }
        }
    }
    return false;
}
}
